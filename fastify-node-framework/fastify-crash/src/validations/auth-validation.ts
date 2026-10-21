import z from "zod";

export const registerSchema = z.object({
    name: z.string().min(2).max(100),
    email : z.string(),
    password : z.string().min(8)
})

export const loginSchema = z.object({
    email : z.string(),
    password : z.string().min(8)
})

export type RegisterSchemaType = z.infer<typeof registerSchema>;
export type loginSchemaType = z.infer<typeof loginSchema>;