// const arr : number[]= [1,2,3,5,3,7,8,9]
// console.log(arr)

// const arrStr :string[]= new Array("kajal","kumari","ghar")
// console.log(arrStr);

// const num : string[] = Array.of("name","kaal","asmk")
// console.log(num[1]);

// const value:object = {name:"kajal",age:23}
// console.log(value);

// const value4 :boolean[]= [true,false,true]
// console.log(value4.length);


// const fruits:string[] = ["apple","banana","orange"];
// const newFruits :number = fruits.push("Kiwi")  //return length
// console.log(fruits,newFruits);

// fruits.pop()
// console.log(fruits);

// for (let index = 0; index < fruits.length; index++) {
//     const element = fruits[index];
//     console.log(element);
// }

// fruits.forEach((element :string) => {
//     console.log(element);
// });


const numbers : number[] = [2,3,4,5,7,8,2,1,3];
// const newNumbers : number[] = numbers.map((ele : number)=> ele*2)
// const newString : string[] = numbers.map((ele)=> ele.toString())
// console.log(numbers,newNumbers,newString);


// const evenNumbers = numbers.filter((ele) => ele%2 === 0);
// console.log(evenNumbers);

// const numbersGreaterThan3 = numbers.filter((ele) => ele >3);
// console.log(numbersGreaterThan3);


const names:string[] = ["kajal","kumari","tiwari"]

const newVersion :string[]= names.map((e)=>e.toUpperCase())
console.log(names,newVersion);

const exponentialNumbers = numbers.map((El : number)=> El*El);
console.log(exponentialNumbers);


const names2 :string[]= ["absdbaiducgddfcjdsbyw","asdjbtudtgfdsktcw","askhdgtfdgw","asjdbyu","sdjfvtsdf"]
const stri:string[] = names2.filter((el)=> el.length>15);

console.log(stri);

const str2 = names2.filter((el)=> el.startsWith("a"))
console.log(str2);
