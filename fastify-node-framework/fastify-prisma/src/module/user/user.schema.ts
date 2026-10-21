import { z } from "zod";
import { buildJsonSchemas } from "fastify-zod";

const userCore = z.object({
  email: z.string().email(),
  name: z.string().min(3),
});

const createUserSchema = userCore.extend({
  password: z.string().min(8),
});

const createUserResponse = userCore;

export type createUserInput = z.infer<typeof createUserSchema>;

const schemas = {
  createUserSchema,
  createUserResponse
};

export const { schemas: userSchemas, $ref } = buildJsonSchemas(schemas, {
  $id: "userSchema"
});