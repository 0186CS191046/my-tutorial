import { type FastifyInstance,type FastifyRequest,type FastifyReply,type FastifyPluginOptions, fastify } from "fastify";
import fp from "fastify-plugin";

const publicRoutes = ["/register","/login"];

const authPlugin = async(fastify:FastifyInstance,opts:FastifyPluginOptions)=>{
    fastify.addHook("onRequest",async(req:FastifyRequest,reply:FastifyReply)=>{
        if(!publicRoutes.includes(req.url)){
            const token = req.headers["authorization"]?.split(" ")[1];
            console.log("token--",token);
            
            if(!token){
                return reply.status(403).send({message:"Forbidden!"})
            }
            try {
                const user = fastify.jwt.verify(token);
                req.user = user;
            } catch (error) {
                return reply.status(401).send({message:"unAuthorized!"})
            }

        }
    })
}

export default fp(authPlugin);