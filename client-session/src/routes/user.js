import express from "express";
import {  getClientId, getUserById, login, logout, register, } from "../controllers/user.js";
import { isAuthenticate } from "../middlewares/auth.js";
const router = express.Router();

router.post("/register",register);
router.post("/login",login);
router.post("/logout",isAuthenticate ,logout);
router.get("/me",isAuthenticate,getUserById);


export default router;