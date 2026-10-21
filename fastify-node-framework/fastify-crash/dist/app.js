import fastify from "fastify";
import { request } from "node:http";
const app = fastify({ logger: true });
app.get("/", async (request, reply) => {
    return { message: "Everything is OK!" };
});
export default app;
