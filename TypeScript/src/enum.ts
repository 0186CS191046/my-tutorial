enum Roles {
    user="user",
    admin = "admin"
}

type LoginDetails = {
    name:string;
    email : string;
    password : string,
    role : Roles
}

const user1 :LoginDetails= {
    name:"Kajal",
    email:"k@gmail.com",
    password : "12345678",
    role : Roles.user
}

const user2 :LoginDetails= {
    name:"Kajal",
    email:"k@gmail.com",
    password : "12345678",
    role : Roles.admin
}

console.log(user1.role);
console.log(user2.role);

const isAdmin :(user:LoginDetails) => string =  (user : LoginDetails) : string=>{
    const {name,email,password,role} = user;
    return role ==="admin" ? `${name} is allow to edit the website` : `${name} is not allow to edit the website`
}

console.log(isAdmin(user1));
console.log(isAdmin(user2));