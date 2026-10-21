import "dotenv/config";

class Env{
    static APP_NAME = process.env.APP_NAME || "Fatsify_Crash_Course"
    static PORT = process.env.PORT? Number(process.env.PORT) : 8000
    static JWT_SECRET = process.env.JWT_SECRET || "qwertyuiopasdfghjklzcvbnm"
    static DATABASE_URL = process.env.DATABASE_URL || "postgresql://postgres:root@localhost:5432/fastify_crash?schema=public"
}

export default Env;