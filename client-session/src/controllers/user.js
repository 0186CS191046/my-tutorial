import User from "../models/user.js";
import jwt from "jsonwebtoken";
import bcrypt from "bcrypt";
import config from "../config/index.js";
import uuid from "uuid4";
import client from "../utils/redis.js";

export const getClientId = async (req, res) => {
    try {
        const clientId = uuid();
        await client.set("sessionId", clientId);
        await client.setEx("sessionId", 15 * 3600, clientId);
        return res.status(200).json({ success: true, message: "Fetched clientId successfully!", clientId })
    } catch (error) {
        return res.status(500).json({ message: "Something went wrong!" })
    }
};

export const register = async (req, res) => {
    try {
        const { firstName, lastName, email, phone, password } = req.body;
        if (!firstName || !lastName || !password || !email || !phone) {
            return res.status(400).json({ message: "Missing required Fields!" })
        };

        const checkUser = await User.findOne({ email });
        if (checkUser) {
            return res.status(400).json({ message: "User already exists!!" })
        }

        const hashPass = await bcrypt.hash(password, 10);
        const newUser = await User.create({ firstName, lastName, email, password: hashPass, phone });

        const token = jwt.sign({ id: newUser._id }, config.jwt_secret_key, { expiresIn: "10m" });
        newUser.token = token
        await newUser.save();

        return res.status(201).json({ success: true, message: "User registered successfully!", user: newUser })
    } catch (error) {
        console.log("Error registering user", error.message);
        return res.status(500).json({ message: "Something went wrong!" })
    }
}

export const login = async (req, res) => {
    try {
        const { email, password } = req.body
        if (!email || !password) {
            return res.status(400).json({ success: false, message: "Missing required firlds!" })
        };

        const user = await User.findOne({ email });

        if (!user) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        }

        const isMatch = await bcrypt.compare(password, user.password);
        if (!isMatch) {
            return res.status(400).json({ success: false, message: "Password didn't match!" })
        }
        const clientId = uuid();
        await client.set(
            `session:${user._id}:${clientId}`,
            "active",
            "EX",
            60 * 15 //15 min
        );
        const accessToken = jwt.sign({ id: user._id, clientId }, config.jwt_secret_key, { expiresIn: "15m" });
        const refreshToken = jwt.sign({ id: user._id, clientId }, config.refresh_secret_key, { expiresIn: "7d" });

        user.isLoggedIn = true;
        await user.save();
        res.cookie('refreshToken', refreshToken, { httpOnly: true, secure: false, sameSite: "Lax" });
        return res.status(200).json({ success: true, message: "Login successfully!", accessToken, user })
    } catch (error) {
        console.log("Error logging user :", error.message);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
}

export const logout = async (req, res) => {
    try {
        const { id, clientId } = req.user;
        console.log("++++++++",req.user);
        

        const checkuser = await User.findById(id);
        if (!checkuser) {
            return res.status(400).json({ success: false, message: "User not exists!" })
        };
        console.log("`session:${id}:${clientId}`",`session:${id}:${clientId}`);
        
        await client.del(`session:${id}:${clientId}`)
        checkuser.token = ""
        await checkuser.save()
        res.clearCookie("refreshToken");
        return res.status(200).json({ success: true, message: "Logout successfully!" })
    } catch (error) {
        console.log("Error in logout user :", error.message);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
};

export const getUserById = async(req,res)=> {
    try {
      const {id} = req.user;
      const user = await User.findById(id).select("-password -token -__v ");
      if(!user){
        return res.status(404).json({ success: false, message: "User not exists!" })
      }
        return res.status(200).json({ success: true, message: "User fetched successfully!",user })
    } catch (error) {
         console.log("Error in fetching user :", error.message);
        return res.status(500).json({ success: false, message: "Something went wrong!" })
    }
}