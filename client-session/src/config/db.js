import mongoose from "mongoose";
import config from "./index.js";

export const connectToDB = async()=>{
    try {
        await mongoose.connect(config.mongodb_url)
        console.log("DB connection successful!");
    } catch (error) {
        console.error("Error connecting to DB :",error.message);   
    }
};


