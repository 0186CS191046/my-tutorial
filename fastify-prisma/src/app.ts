import Fastify from "fastify";
import userRoutes from "./module/user/user.route";

const server = Fastify();

server.get("/health",()=>{
    return{status:"OK"}
})

async function main(){
    server.register(userRoutes,{prefix:"api/user"});
    try {
        await server.listen(4000, "0.0.0.0");
        console.log("Server is running on http://localhost:4000");
    } catch (error) {
        console.error(error);
        process.exit(1);
    }
}
main();