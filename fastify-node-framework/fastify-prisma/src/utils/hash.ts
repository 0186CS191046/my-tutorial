import crypto from "crypto";

export const hashPassword = (passw:string)=>{
    const salt = crypto.randomBytes(16).toString("hex");

    const hash = crypto.pbkdf2Sync(passw,salt,1000,64,"sha512").toString("hex")
    return {hash,salt};
}

export const verifyPassword  = (passw:string,hash:string,salt:string) =>{
    const candidatepassword = crypto.pbkdf2Sync(passw,salt,1000,64,"sha512").toString("hex")
    return candidatepassword=== hash
}
