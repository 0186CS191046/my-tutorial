import nodemailer from "nodemailer";
import config from "../config/index.js";

const transporter = await nodemailer.createTransport({
    service: "gmail",
    auth: {
        user: config.mail_user,
        pass: config.mail_pass
    }
});

export const emailVerify = (token, email) => {
    const mailConfig = {
        from: "kumarikajal89681@gmail.com",
        to: email,
        subject: "Email Verification",
        text: `Hi! There, 
        You have recently visited our website and entered your email http://localhost:5173/verify/${token}
        Thanks`
    }

    transporter.sendMail(mailConfig, function (err, info) {
        if (err) throw Error(err);
        console.log("Email sent successfully!");
        console.log(info);
    })
}

export const sendOTPEmail = async(email,otp)=>{
    try {
        const mailConfig = {
        from: "kumarikajal89681@gmail.com",
        to: email,
        subject: "Password Reset OTP",
        html: `<p>Your OTP for password reset <b>${otp}</b></p>`
    }

    transporter.sendMail(mailConfig, function (err, info) {
        if (err) throw Error(err);
        console.log("Email sent successfully!");
        console.log(info);
    })
    } catch (error) {
        return res.status(500).json({success : false, message:""})
        
    }
}