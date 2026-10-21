import { hashPassword } from "../../utils/hash";
import prisma from "../../utils/prisma"
import { createUserInput } from "./user.schema"

export const createUser = async (input: createUserInput) => {
    const { password, ...rest } = input;

    const { hash, salt } = hashPassword(password);

    console.log("rest----------",rest,salt,hash);
    

    const user = await prisma.user.create({ data: { ...rest, salt, password: hash } });
    return user;
}