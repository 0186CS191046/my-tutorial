import config from "../config/index.js";
import jwt from "jsonwebtoken"
import User from "../models/user.js";
import client from "../utils/redis.js";

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
            const key = `session:${decode.id}:${decode.clientId}`
            const exists = await client.get(key);
``
            if (!exists) {
                return res.status(401).json({ message: "Session expired / invalid" });
            }
        } catch (error) {
            if (error.name == "TokenExpiredError") {
                return res.status(400).json({ success: false, message: "Token Expired!" })
            }
            return res.status(500).json({ success: false, message: "Token verification failed!" })
        }
        // let user = await User.findById(decode.id);
        // if (!user) {
        //     return res.status(400).json({ success: false, message: "User not exists!" })
        // }
        
        req.user = {id:decode.id,clientId:decode.clientId}
        next()
    } catch (error) {
        console.log("Error in isAuthenticate middleware:", error.message);
        return res.status(500).json({ success: false, message: "User is not authenticated!" })
    }
}