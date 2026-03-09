// class Persons {
//     name: string;
//     age: number
//     hobbies: string[];
//     constructor(name: string, age: number, hobbies: string[]) {
//         this.name = name;
//         this.age = age;
//         this.hobbies = hobbies
//     }
//     introduce() :string{
//         return `Hello , My name is ${this.name}, My age is ${this.age} , My hobbies are ${this.hobbies.join(",")}`
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
//         return `${super.introduce()}. My grade is ${this.grade}`
//     }
// }
// class Teacher extends Persons { }
// // const p1a = new Persons("Kajal",24,["reading","internet"]);
// // const p2a = new Persons("Kumari",21,["watching movies", "travelling"])
// // console.log(p1a.introduce());
// // console.log(p2a);
// const p1w1 = new Persons("Kajal", 24, ["reading", "internet"])
// const st1 = new Students("Kajal", 24, ["reading", "internet"],34)
// console.log(p1w1.introduce());
// console.log(st1.introduce());
