import express from "express";
import config from "./src/config/index.js";
import { connectToDB } from "./src/config/db.js";
import userRoutes from "./src/routes/user.js";
// import {redisConnect} from "./src/utils/redis.js";
import path ,{dirname }from "path";
import { fileURLToPath } from 'url';
const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

connectToDB();
// redisConnect();

const app = express();
app.use("/", express.static(path.join(__dirname,"views")));
// app.use("/signup",express.static(path.join(__dirname,"views","signup.html")));

app.use(express.json());
app.use(express.urlencoded({extended:true}));


app.use(userRoutes);

// app.get("/",(req,res)=>{
//     res.json("Everything is OK!")
// });

app.listen(config.port,()=>{
    console.log("Server is listening on port :",config.port);
})