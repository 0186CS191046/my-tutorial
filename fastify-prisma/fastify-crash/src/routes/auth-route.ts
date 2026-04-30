import type { FastifyInstance,FastifyPluginOptions,FastifyRequest, FastifyReply } from "fastify";
import { loginSchema, registerSchema, type loginSchemaType, type RegisterSchemaType } from "../validations/auth-validation.js";
import { email } from "zod";
import { comparePassword, hashPassword } from "../utils/helper.js";
import bcrypt from "bcrypt";

const authRoutes = async(app:FastifyInstance,opts:FastifyPluginOptions)=>{
    app.post("/register", {schema:{body:registerSchema}} , async(req:FastifyRequest,reply:FastifyReply)=>{
        const body = req.body as RegisterSchemaType;
        const isUserExist = await app.prisma.user.findUnique({where:{email:body.email}});

        if(isUserExist){
            return reply.status(400).send({message:"User already exists with the same email..."})
        }

        const hashPasswor = await hashPassword(body.password);
        const newUser = await app.prisma.user.create({data:{
            name:body.name,email:body.email,password:hashPasswor
        }});

        return reply.status(201).send({message:"User created successfully..."})
    });

    app.post("/login",{schema:{body:loginSchema}},async(req:FastifyRequest,reply:FastifyReply)=>{
        const {email,password} = req.body as loginSchemaType;

        const isUserExist = await app.prisma.user.findUnique({where:{email}});
        if(!isUserExist){
            return reply.status(400).send({message:"User not exists!"})
        }
        const isPasswordMatch =  await comparePassword(isUserExist.password,password);
        
        if(!isPasswordMatch){
            return reply.status(400).send({message:"Password didn't match!"})
        }
        const payload = {id:isUserExist.id,name:isUserExist.name,email:isUserExist.email}
        const token = await app.jwt.sign(payload,{expiresIn:"15min"})
        return reply.status(200).send({message:"User Login successfully!",token})
    })
};

export default authRoutes;