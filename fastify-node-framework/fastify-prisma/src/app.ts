import Fastify from "fastify";
import userRoutes from "./module/user/user.route";
import { userSchemas } from "./module/user/user.schema";

const server = Fastify();

server.get("/health",()=>{
    return{status:"OK"}
})

async function main(){
    console.log(userSchemas);
    for(const schema of userSchemas){
        server.addSchema(schema);
    }
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


