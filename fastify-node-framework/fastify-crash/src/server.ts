import app from "./app.js";
import Env from "./utils/env.js";

const start = async()=>{
    await app.listen({port:Env.PORT});
    console.log("Server is listening on port 8000");
}

start();