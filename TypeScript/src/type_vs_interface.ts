// type Stud ={
//     name:string;
//     age:number
// }
// type StuAdd = {
//     city:string;
//     country : string
// }

// const BioData:Stud = {
//     name:"Kajal",
//     age:24
// }

// const BioData:Stud |StuAdd= {
//     name:"Kajal",
//     age:24,
//     city:"Noida"
// }

// const BioData:Stud & StuAdd= {
//     name:"Kajal",
//     age:24,
//     city:"Noida",
//     country:"India"
// }
// type Data = Stud |StuAdd

// const BioData:Data= {
//     name:"Kajal",
//     age:24,
//     city:"Noida"
// }

// console.log(BioData);


interface Stud {
    name: string;
    age: number;
}

interface StuAdd {
    city: string;
    country: string;
}

interface Data extends Stud, StuAdd { }

// const BioData: Data = {
//     name: "Kajal",
//     age: 24,
//     city: "Noida",
//     country: "India"
// }

// console.log(BioData);

class BioData implements Data {
    constructor(
        public name: string,
        public age: number,
        public city: string,
        public country: string
    ) { }

}

const st12 = new BioData("Kajal",24,"Noida","India")

console.log(st12);
