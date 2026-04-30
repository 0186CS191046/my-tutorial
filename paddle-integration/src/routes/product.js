import express from "express";
import { isAdmin, isAuthenticate } from "../middlewares/auth.js";
import { multipleUpload } from "../middlewares/multer.js";
import { addProduct, getProducts } from "../controllers/product.js";
const router = express.Router();

router.post("/product",isAuthenticate,isAdmin,multipleUpload, addProduct);
router.get("/product",getProducts)

export default router;