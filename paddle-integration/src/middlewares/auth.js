import config from "../config/index.js";
import jwt from "jsonwebtoken"
import User from "../models/user.js";

export const isAuthenticate = async (req, res, next) => {
    try {
        const authHeader = req.headers.authorization;
        if (!authHeader || !authHeader.startsWith("Bearer")) {
            return res.status(400).json({ success: false, message: "Missing Token!" })
        }

        const token = authHeader.split(" ")[1];
        let decode;
        try {
            decode = jwt.verify(token, config.jwt_secret_key);
        } catch (error) {
            if (error.name == "TokenExpiredError") {
                return res.status(400).json({ success: false, message: "Token Expired!" })
            }
            return res.status(500).json({ success: false, message: "Token verification failed!" })
        }
        console.log("decode", decode);
        const user = await User.findById(decode.id);
        if(!user){
            return res.status(400).json({ success: false, message: "User not exists!" })
        }
        req.user = user
        next()
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "User is not authenticated!" })
    }
}

export const isAdmin = async (req, res, next) => {
    try {
        const user = req.user
        console.log("user",user);
        
        if (user.role !== "admin") {
            return res.status(400).json({ success: false, message: "Access Denied : admins only" })
        }
        next()
    } catch (error) {
        console.log(error);
        return res.status(500).json({ success: false, message: "User is not authenticated!" })
    }
}