// type Stud ={
//     name:string;
//     age:number
// }
// type StuAdd = {
//     city:string;
//     country : string
// }
// const BioData: Data = {
//     name: "Kajal",
//     age: 24,
//     city: "Noida",
//     country: "India"
// }
// console.log(BioData);
class BioData {
    constructor(name, age, city, country) {
        this.name = name;
        this.age = age;
        this.city = city;
        this.country = country;
    }
}
const st12 = new BioData("Kajal", 24, "Noida", "India");
console.log(st12);
