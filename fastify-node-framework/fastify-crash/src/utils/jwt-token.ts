import type {FastifyJWTOptions} from "@fastify/jwt";
import Env from "./env.js";

const jwtOptions :FastifyJWTOptions={
    secret:Env.JWT_SECRET,
    sign:{
        expiresIn:"7d",
        algorithm:"HS256"
    }
} 

export default jwtOptions;