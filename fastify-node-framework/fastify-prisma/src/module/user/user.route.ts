import {FastifyInstance} from "fastify";
import {registerUser} from "./user.controller"
import { $ref } from "./user.schema";

async function userRoutes(server:FastifyInstance) {
    server.post("/register", {
  schema: {
    body: "createUserSchema",
    response: {
      201: "createUserResponse",
    },
  },
}, registerUser);
}

export default userRoutes;