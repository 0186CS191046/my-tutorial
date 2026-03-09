// class Persons {
//     public name: string;
//     protected age: number
//     private hobbies: string[];
//     constructor(name: string, age: number, hobbies: string[]) {
//         this.name = name;
//         this.age = age;
//         this.hobbies = hobbies
//     }
//     introduce() :string{
//         return `Hello , My name is ${this.name}, My age is ${this.age} , My hobbies are ${this.hobbies.join(",")}` //private, we can access only this class
//     }
// }
// class Students extends Persons {
//     grade: number;
//     constructor( name: string, age: number, hobbies: string[],grade: number) {
//         super(name, age, hobbies)
//         this.grade = grade
//     }
//     introduce(): string {
//         // return `Hello , My name is ${this.name}, My age is ${this.age} , My hobbies are ${this.hobbies.join(",")}. My grade is ${this.grade}`
//         return `My age is ${this.age}`  //protected, we can access here
//     }
// }
// const p1w1 = new Persons("Kajal", 24, ["reading", "internet"])
// const st1 = new Students("Kajal", 24, ["reading", "internet"],34)
// console.log(p1w1.name);  //public  , we can access
// console.log(st1.introduce()); 
// can also write like this, shorthand property
class Persons {
    constructor(name, age, hobbies) {
        this.name = name;
        this.age = age;
        this.hobbies = hobbies;
    }
    introduce() {
        return `Hello , My name is ${this.name}, My age is ${this.age} , My hobbies are ${this.hobbies.join(",")}`; //private, we can access only this class
    }
}
