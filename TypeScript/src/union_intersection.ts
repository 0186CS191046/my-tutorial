// const inputValue:(value:string|number)=> string|number = (value:string|number):string|number => {return value}

// inputValue(55);
// inputValue("kajal")

// console.log(inputValue("kajal"));
// console.log(inputValue(55));

// const userInput = (value : string|number) => {
//     if(typeof value =="number"){
//         return value*3
//     }
//     else if(typeof value=="string"){
//         return value.toUpperCase()
//     }else{
//        throw Error("Invalid Data Types")
//     }
// }

// console.log(userInput("Kajal"));
// console.log(userInput(67));


// const formatResult = (value : string|number|boolean) => {
//     if(typeof value =="string"){
//         const upper = value[0].toUpperCase()
//         console.log(upper);
//         return upper + value.slice(1)
//     }else if(typeof value =="number"){
//         return `$${value.toFixed(2)}$`
//     }else if(typeof value == "boolean"){
//         return value?"Yes":"No"
//     }
// }

// console.log(formatResult("kajal"));
// console.log(formatResult(34));
// console.log(formatResult(true));


// type Person = {
//     name:string,
//     age:number
// }

// type Employee = {
//     emp_id : number,
//     department : string
// }

// type EmployeeDetails = Person & Employee

// const employee :EmployeeDetails ={
//     name:"Kajal",
//     age:23,
//     emp_id:23,
//     department : "IT"
// } 


// const myPersonalInfo : Person = {
//     name:"Kumari",
//     age:34
// }

// type user = {
//     name:string,
//     age:number
// }

// type Loc = {
//     city:string,
//     country : string
// }

// const u1 : user = {
//     name:"Kumari",
//     age:34
// }

// const myloc :Loc = {city:"Deoria", country:"India"};

// const userProfile:(user :user, location : Loc) =>string = (user:user,location : Loc):string =>{
//     return `My name is ${user.name} and I am from ${location.city} ${location.country}`
// }

// console.log(userProfile(u1,myloc));

// type userProfile = user & Loc

// const userProfile = (user:user,location : Loc):userProfile =>{
//     return {...user,...location}
// }

// const myCompleteInfo :userProfile = userProfile(u1,myloc)

// console.log(myCompleteInfo);

type User = {
    id:number;
    name:string;
    email : string
}

type Account = {
    accountId : number,
    accountType : string;
    balance : number
}

type UserAccount = User & Account

const u1:User = {
    id:1,
    name:"Kajal",
    email:"kajal.kumari@ficode.com"

}

const acc :Account= {
    accountId : 4567890345567,
    accountType:"Savings",
    balance:30000
}
const combineUserAndAccount = ((user:User,account:Account):UserAccount =>{
    return {...user,...account}
})

console.log(combineUserAndAccount(u1,acc));
