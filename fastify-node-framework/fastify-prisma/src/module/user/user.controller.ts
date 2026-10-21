import {FastifyRequest,FastifyReply} from "fastify";
import { createUser } from "./user.services";
import { createUserInput } from "./user.schema";

export const registerUser = async(request:FastifyRequest<{Body:createUserInput}>,reply:FastifyReply)=>{
    try {
      const body = request.body;
      const newUser = await createUser(body);
      return reply.status(201).send({message: "User registered successfully!",user:newUser});
    } catch (error:any) {
        console.log("Error in creating user : ",error.message);
        return reply.status(500).send({message:"Internal Server Error!"})
        
    }
}