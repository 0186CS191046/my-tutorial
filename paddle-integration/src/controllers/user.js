import User from "../models/user.js";
import { emailVerify, sendOTPEmail } from "../utils/email-send.js";
import jwt from "jsonwebtoken";
import bcrypt from "bcrypt";
import config from "../config/index.js";
import Session from "../models/session.js";
import cloudinary from "../utils/cloudinary.js";
import axios from "axios";

export const register = async (req, res) => {
    try {
        const { firstName, lastName, email, password } = req.body;
        if (!firstName || !lastName || !password || !email) {
            return res.status(400).json({ message: "Missing required Fields!" })
        };

        const checkUser = await User.findOne({ email });
        if (checkUser) {
            return res.status(400).json({ message: "User already exists!!" })
        }

        const hashPass = await bcrypt.hash(password, 10);
        const newUser = await User.create({ firstName, lastName, email, password: hashPass });

        const token = jwt.sign({ id: newUser._id }, config.jwt_secret_key, { expiresIn: "10m" });
        emailVerify(token, email);
        newUser.token = token
        await newUser.save();

        return res.status(210).json({ success: true, message: "User registered successfully!", user: newUser })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ message: "Something went wrong!" })
    }
}

export const verifyEmail = async (req, res) => {
    try {
        const reqheader = req.headers.authorization
        if (!reqheader || !reqheader.startsWith("Bearer")) {
            return res.status(400).json({ success: false, message: "Missing Authheader" })
        };
        const token = reqheader.split(" ")[1]
        let decode

        try {
            decode = jwt.verify(token, config.jwt_secret_key);

        } catch (error) {
            if (error.name == "TokenExpiredError") {
                return res.status(400).json({ success: false, message: "A registration token has expired" })
            }
            return res.status(400).json({ success: false, message: "Token verification failed!" })

        }
        console.log(decode);

        const user = await User.findById(decode.id);
        console.log(user);

        if (!user) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        }
        user.token = null
        user.isEmailVerified = true;
        await user.save();
        return res.status(200).json({ success: true, message: "Email verified successfully!" })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
};

export const resendEmailVerification = async (req, res) => {
    try {
        const { email } = req.body
        if (!email) {
            return res.status(400).json({ success: false, message: "Missing Authheader" })
        };

        const user = await User.findOne({ email });
        console.log(user);

        if (!user) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        }

        const token = jwt.sign({ id: user._id }, config.jwt_secret_key, { expiresIn: "10m" });
        emailVerify(token, email);

        user.token = token
        await user.save();
        return res.status(200).json({ success: true, message: "Email resent successfully!" })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
}

export const login = async (req, res) => {
    try {
        const { email, password } = req.body
        if (!email || !password) {
            return res.status(400).json({ success: false, message: "Missing required firlds!" })
        };

        const user = await User.findOne({ email });
        console.log(user);

        if (!user) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        }

        const isMatch = await bcrypt.compare(password, user.password);
        if (!isMatch) {
            return res.status(400).json({ success: false, message: "Password didn't match!" })
        }
        if (!user.isEmailVerified) {
            return res.status(400).json({ success: false, message: "Please verify your email!" })
        }
        const accessToken = jwt.sign({ id: user._id }, config.jwt_secret_key, { expiresIn: "11h" });
        const refreshToken = jwt.sign({ id: user._id }, config.jwt_secret_key, { expiresIn: "30d" });
        const checkSession = await Session.findById(user._id);
        if (checkSession) {
            await Session.deleteMany({ userId: user._id })
        }
        await Session.create({ userId: user._id })

        user.isLoggedIn = true;
        await user.save();
        return res.status(200).json({ success: true, message: "Login successfully!", accessToken, refreshToken, user })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
}

export const logout = async (req, res) => {
    try {
        const { id } = req.user;
        console.log("id", id);

        const checkuser = await User.findById(id);
        if (!checkuser) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        };
        console.log(checkuser);

        await Session.deleteMany({ userId: checkuser._id })
        checkuser.isLoggedIn = false
        await checkuser.save()

        return res.status(200).json({ success: true, message: "Logout successfully!" })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
};

export const forgotPassword = async (req, res) => {
    try {
        const { email } = req.body

        if (!email) {
            return res.status(400).json({ success: false, message: "Missing required fields!" })
        };

        const user = await User.findOne({ email });
        console.log(user);

        if (!user) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        }

        const otp = Math.floor(100000 + Math.random() * 90000).toString()
        const otpExpiry = new Date(Date.now() + 10 * 60 * 1000)

        user.otp = otp;
        user.otpExpiry = otpExpiry

        await user.save();

        await sendOTPEmail(email, otp)
        return res.status(200).json({ success: true, message: "OTP sent successfully!" })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
}

export const verifyOTP = async (req, res) => {
    try {
        const { otp } = req.body
        const email = req.params.email
        if (!email || !otp) {
            return res.status(400).json({ success: false, message: "Missing required fields!" })
        };

        const user = await User.findOne({ email });
        console.log(user);

        if (!user) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        }
        if (!user.otp || !user.otpExpiry) {
            return res.status(400).json({ success: false, message: "OTP is not generated or already verified!" })
        }
        if (user.otpExpiry < new Date()) {
            return res.status(400).json({ success: false, message: "OTP has expired, please generate a new one!" })
        }
        if (user.otp !== otp) {
            return res.status(400).json({ success: false, message: "OTP is invalid!" })
        }
        user.otp = null;
        user.otpExpiry = null
        await user.save();

        return res.status(200).json({ success: true, message: "OTP verified successfully!" })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
};

export const changePassword = async (req, res) => {
    try {
        const { password, confirmPassword } = req.body;
        const email = req.params.email

        if (!email || !password || !confirmPassword) {
            return res.status(400).json({ success: false, message: "Missing required fields!" })
        };

        const user = await User.findOne({ email });
        console.log(user);

        if (!user) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        }

        if (password !== confirmPassword) {
            return res.status(400).json({ success: false, message: "Password didn't match!" })
        }
        const hashPass = await bcrypt.hash(password, 10);
        user.password = hashPass
        await user.save();
        return res.status(200).json({ success: true, message: "Password changed successfully!" })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
}

export const getAllUsers = async (req, res) => {
    try {
        const allusers = await User.find();
        return res.status(200).json({ success: true, message: "Users fetched successfully!", users: allusers })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
}

export const getUserById = async (req, res) => {
    try {
        const { id } = req.params
        const user = await User.findById(id).select("-password -token -otp -otpExpiry ");
        if (!user) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        }
        return res.status(200).json({ success: true, message: "Users fetched successfully!", users: user })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
};

export const updateUser = async (req, res) => {
    try {
        const { id } = req.params
        const loggedInuser = req.user
        const { firstName, lastName, phoneNo, address, city, zipcode, role } = req.body;

        if (loggedInuser._id.toString() !== id && loggedInuser.role !== "admin") {
            return res.status(400).json({ success: false, message: "You are not allowed to update this profile!" })
        };

        let user = await User.findById(id);
        if (!user) {
            return res.status(403).json({ success: false, message: "User not exists!" })
        }

        let profilePicUrl = user.profilePic;
        let profilePicPublicId = user.profilePicPublicId;

        if (req.file) {
            if (profilePicPublicId) {
                await cloudinary.uploader.destroy(profilePicPublicId)
            }

            const uploadResult = await new Promise((res, rej) => {
                const stream = cloudinary.uploader.upload_stream({
                    folder: "profiles"
                },
                    (error, result) => {
                        if (error) rej(error);
                        else { res(result) }
                    }
                );

                stream.end(req.file.buffer);
            })
            profilePicUrl = uploadResult.secure_url;
            profilePicPublicId = uploadResult.public_id

        }

        user.firstName = firstName || user.firstName;
        user.lastName = lastName || user.lastName;
        user.phoneNumber = phoneNo || user.phoneNumber;
        user.address = address || user.address;
        user.city = city || user.city;
        user.zipcode = zipcode || user.zipcode;
        user.profilePic = profilePicUrl;
        user.profilePicPublicId = profilePicPublicId;
        user.role = role

        const updatedUser = await user.save()
        return res.status(200).json({ success: true, message: "Users updated successfully!", user: updatedUser })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
};

export const getPaddlePlans = async (req, res) => {
    try {
        const resp = await axios.get(`https://sandbox-api.paddle.com/prices`, {
            headers: {
                'Authorization': `Bearer ${config.paddle_api_key}`
            }
        });

        return res.status(200).json({ success: true, data: resp.data.data })
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
};


export const webhookPaddle = async (req, res) => {
    try {
        const event = req.event ;
        console.log("Webhook received:", event);
        switch (event.event_type) {

            case "transaction.completed":
                console.log(event.data);
                break;

            case "transaction.payment_failed":
                console.log(event.data);
                break;

            case "subscription.created":
                console.log(event.data);
                break;

            case "subscription.canceled":
                console.log(event.data);
                break;
        }

        return res.status(200).json({ success: true, message: "Webhook received!" })

    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
}