var Roles;
(function (Roles) {
    Roles["user"] = "user";
    Roles["admin"] = "admin";
})(Roles || (Roles = {}));
const user1 = {
    name: "Kajal",
    email: "k@gmail.com",
    password: "12345678",
    role: Roles.user
};
const user2 = {
    name: "Kajal",
    email: "k@gmail.com",
    password: "12345678",
    role: Roles.admin
};
console.log(user1.role);
console.log(user2.role);
const isAdmin = (user) => {
    const { name, email, password, role } = user;
    return role === "admin" ? `${name} is allow to edit the website` : `${name} is not allow to edit the website`;
};
console.log(isAdmin(user1));
console.log(isAdmin(user2));
