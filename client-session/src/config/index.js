import dotenv from "dotenv";
dotenv.config();

const config = {
    port : process.env.PORT,
    mongodb_url : process.env.MONGODB_URL,
    jwt_secret_key : process.env.JWT_SECRET_KEY, 
    refresh_secret_key : process.env.REFRESH_SECRET_KEY
};

export default config;