import type { FastifyInstance ,FastifyRequest,FastifyReply,FastifyPluginOptions} from "fastify";

const userRoutes = async(app:FastifyInstance,opts:FastifyPluginOptions)=>{
    app.get("/user-profile",async(req:FastifyRequest,reply : FastifyReply)=>{
        return reply.status(200).send({message:"User fetched successfully!",user:req.user})
    })
}

export default userRoutes;