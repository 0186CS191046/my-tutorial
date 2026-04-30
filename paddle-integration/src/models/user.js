import { Schema, model } from "mongoose";

const userSchema = new Schema({
    firstName: { type: String, required: true },
    lastName: { type: String, required: true },
    email: {
        type: String,
        unique: true,
        required: true
    },
    password: {
        type: String,
        required: true
    },
    profilePic: {
        type: String,
        default: ""
    },
    profilePicPublicId: {  //for delete image from cloudinary
        type: String
    },
    role: {
        type: String,
        enum: ["user", "admin"],
        default: "user"
    },
    isLoggedIn: {
        type: Boolean,
        default: false
    },
    isEmailVerified: {
        type: Boolean,
        default: false
    },
    otp: {
        type: String,
        default: null
    },
    otpExpiry: {
        type: Date,
        default: null
    },
    token: {
        type: String,
        default: null
    },
    address: {
        type: String
    },
    city: {
        type: String,
    },
    zipcode: {
        type: String
    },
    city: {
        type: String

    },
    phoneNumber: {
        type: String
    }
}, { timestamps: true })

const User = model("User",userSchema);

export default User;