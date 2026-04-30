import dotenv from "dotenv";
dotenv.config();

const config = {
    port : process.env.PORT,
    mongodb_url : process.env.MONGODB_URL,
    mail_user : process.env.MAIL_USER ,
    mail_pass : process.env.MAIL_PASS,
    jwt_secret_key : process.env.JWT_SECRET_KEY,
    cloud_name : process.env.CLOUD_NAME,
    cloud_api_key : process.env.CLOUD_API_KEY,
    cloud_api_secret : process.env.CLOUD_API_SECRET,
    paddle_api_key : process.env.PADDLE_API_KEY
}

export default config;