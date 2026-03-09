// class Person{
//     name:string = "Kajal";
//     age:number = 24;
//     hobbies : string[] =  ["reading", "suffering on internet!"]
// }

// const p1 = new Person();

// console.log(p1);


class Person{
    name:string ;
    age:number 
    hobbies : string[] ;

    constructor (name:string,age:number,hobbies:string[]){
        this.name = name;
        this.age = age;
        this.hobbies = hobbies
    }
}

const p1 = new Person("Kajal",24,["reading","internet"]);
const p2 = new Person("Kumari",21,["watching movies", "travelling"])

console.log(p1);
console.log(p2);
