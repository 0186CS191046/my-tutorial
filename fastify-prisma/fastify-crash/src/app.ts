import fastify from "fastify";
import fastifyCors from "@fastify/cors";
import fastifyHelmet from "@fastify/helmet";
import {serializerCompiler, validatorCompiler, type ZodTypeProvider} from "fastify-type-provider-zod";
import dbPlugin from "./plugins/db-plugin.js";
import jwt from "@fastify/jwt";
import authRoutes from "./routes/auth-route.js";
import jwtOptions from "./utils/jwt-token.js";
import userRoutes from "./routes/user-route.js";
import authPlugin from "./plugins/auth-route.js"

const app = fastify({logger:true}).withTypeProvider<ZodTypeProvider>();

app.register(fastifyCors);
app.register(fastifyHelmet);
app.register(dbPlugin);
app.register(jwt, jwtOptions);
app.register(authPlugin);

app.register(authRoutes);
app.register(userRoutes);
// app.register(authRoutes,{prefix:"/api/auth"}); //we can also write like this

app.setValidatorCompiler(validatorCompiler);
app.setSerializerCompiler(serializerCompiler);
app.get("/",async(request,reply)=>{
    return {message:"Everything is OK!"}
});

app.setErrorHandler(function(error:any,request,reply){
    console.log("Error----------",error);
    if("validation" in error && Array.isArray((error as any).validation)){
        const validationErrors = (error as any).validation;
        const errors = validationErrors.map((issue:{instancePath:string,message:string})=>({
            field:issue.instancePath.substring(1),
            message:issue.message
        }))
        reply.status(422).send({message:"Please fill all required fields!",errors})
    }
})

export default app;