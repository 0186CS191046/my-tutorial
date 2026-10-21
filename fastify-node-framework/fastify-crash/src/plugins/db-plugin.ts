import type { FastifyInstance, FastifyPluginAsync, FastifyPluginOptions} from "fastify";
import { PrismaClient } from "@prisma/client";
import fp from "fastify-plugin";
import Env from "../utils/env.js";

declare module "fastify" {
    interface FastifyInstance{
        prisma:PrismaClient
    }
}
const dbPlugin:FastifyPluginAsync = async(fastify:FastifyInstance,opts:FastifyPluginOptions)=>{
    console.log();
    
    const prisma = new PrismaClient();
    
    await prisma.$connect();

    fastify.decorate("prisma",prisma);

    fastify.addHook("onClose",async(instance:FastifyInstance)=>{
        await instance.prisma.$disconnect();
    })
};

export default fp(dbPlugin);