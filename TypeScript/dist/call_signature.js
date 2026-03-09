// type GreetType = {
//     (name : string) :string,
//     description : string
// }
const stud1 = {
    name: "Kajal",
    age: 24,
    greet: ((country) => { return `Welcome my name is ${stud1.name} and my age is ${stud1.age}, I am from ${country}`; })
};
console.log(stud1.age);
// const introduction :(stud1:Student) => string = (stud1:Student):string => {
//     const {name,age} = stud1;
//     return `Welcome my name is ${name} and my age is ${age}`
// }
console.log(stud1.greet("India"));
