import Product from "../models/product.js";
import cloudinary from "../utils/cloudinary.js";
import getdataUri from "../utils/datauri.js";

export const addProduct = async (req, res) => {
    try {
        const { productName, productDesc, price, brand, category } = req.body;
        const userId = req.id

        console.log(req.body);

        if (!productName || !productDesc || !price || !brand || !category) {
            return res.status(400).json({ success: false, message: "Missing required fields!" })
        }

        let productImg = []
        if (req.files && req.files.length > 0) {
            for (let file of req.files) {
                const fileUri = getdataUri(file);
                const result = await cloudinary.uploader.upload(fileUri, {
                    folder: "products/"
                })

                productImg.push({ url: result.secure_url, publicId: result.public_id })
            }
        }

        const newproduct = await Product.create({
            productName, productDesc, price, category, brand,
            productImg, //array of objects [{uri : "",publicId : ""}]
            userId
        });

        return res.status(201).json({ success: true, message: "Product created successfully!", product: newproduct })
    } catch (error) {
        return res.status(500).json({ success: false, message: "Something went wrong!", error: error.message })
    }
}

export const getProducts = async (req, res) => {
    try {
        const products = await Product.find();
        if (!products) {
            return res.status(404).json({ success: false, message: "No products availabel!", products: [] })
        }
        return res.status(200).json({ success: true, message: "Products fetched successfully!", products })
    } catch (error) {
        return res.status(500).json({ success: false, message: "Something went wrong!", error: error.message })
    }
}

export const deleteProduct = async (req, res) => {
    try {
        const { productId } = req.params;

        const checkProduct = await Product.findById(productId);
        if (!checkProduct) {
            return res.status(404).json({ success: false, message: "Product not exists!" })
        }

        if (checkProduct.productImg && checkProduct.productImg.length > 0) {
            for (let img of checkProduct.productImg) {
                await cloudinary.uploader.destroy(img.publicId)
            }
        }
        await Product.findByIdAndDelete(productId)
        return res.status(200).json({ success: true, message: "Product deleted successfully!" })
    } catch (error) {
        return res.status(500).json({ success: false, message: "Something went wrong!", error: error.message })
    }
}

export const updateProduct = async (req, res) => {
    try {
        const { productId } = req.params;
        const { productName, productDesc, price, brand, category, existingImages } = req.body;
        const product = await Product.findById(productId);
        if (!product) {
            return res.status(404).json({ success: false, message: "Product not exists!" })
        };
        let updatedImages = [];
        // keep selected images
        if (existingImages) {
            const keepIds = JSON.parse(existingImages);
            updatedImages = product.productImg.filter((img) => {
                keepIds.includes(img.publicId);
            });
            //delete only removed images
            const removedImages = product.productImg.filter((img) => {
                !keepIds.includes(img.publicId);
            })
            for (let img of removedImages) {
                await cloudinary.uploader.destroy(img.publicId)
            }
        } else {
            updatedImages = product.productImg //keep all if nothing sent
        }

        if (req.files && req.files.length > 0) {
            for (let file of req.files) {
                const fileUri = getdataUri(file);
                const result = await cloudinary.uploader.upload(fileUri, {
                    folder: "products/"
                })
                updatedImages.push({ uri: result.secure_url, publicId: result.public_id });
            }
        }

        //update product
        product.productName = productName || product?.productName;
        product.productDesc = productDesc || product?.productDesc;
        product.price = price || product?.price;
        product.brand = brand || product?.brand;
        product.category = category || product?.category;
        product.productImg = updatedImages;

    } catch (error) {
        return res.status(500).json({ success: false, message: "Something went wrong!", error: error.message })
    }
}