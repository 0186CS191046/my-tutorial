// type GreetType = {
//     (name : string) :string,
//     description : string
// }

// const greet1 :GreetType = (name:string)=> {return `Hello ${name}`}
// greet1.description = "Hello this is testing!"

// console.log(greet1("Kajal"));
// console.log(greet1.description);


type Student = {
    name : string;
    age:number;
    gender?:string
    greet : (country :string) => string
}

const stud1:Student = {
    name:"Kajal",
    age:24,
    greet : ((country:string) :string=> {return `Welcome my name is ${stud1.name} and my age is ${stud1.age}, I am from ${country}`})
}

console.log(stud1.age);


// const introduction :(stud1:Student) => string = (stud1:Student):string => {
//     const {name,age} = stud1;

//     return `Welcome my name is ${name} and my age is ${age}`
// }

console.log(stud1.greet("India"));
