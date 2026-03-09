// function greet(name:string,age:number){
//     console.log(`Welcome ${name}, Is your age is ${age}?`);   
// }
// const greet = (name:string,age:number):void=>{
//     console.log(`Welcome ${name}, Is your age is ${age}?`);   
// }
// greet("Kajal",24)
// function isPalindrome(str:string) : boolean{
//    const palin = str.split("").reverse().join("");
//    return palin === str
// }
// console.log(isPalindrome("12321"))
// function calculateAverage(numbers : number[]) :number{
//    const sum =  numbers.reduce((accum,curr)=> accum+curr,0 )
//    console.log(sum);
//    return Number((sum/numbers.length).toFixed(2))
// }
// console.log(calculateAverage([2,4,6,8,3,1,4,6,8]));
// function findMaxValue(numbers:number[]){
//     const maxValue = numbers.reduce((accum,curr)=> Math.max(accum,curr),-1)
//     console.log(maxValue);
// }
// findMaxValue([2,4,6,8,3,1,4,6,24]);
// const greet = (name:string,age:number = 24):void=>{
//     console.log(`Welcome ${name}, Is your age is ${age}?`);   
// }
// greet("Kajal")
const greet = (name, age) => {
    if (age) {
        console.log(`Welcome ${name}, Is your age is ${age}?`);
    }
    else {
        console.log(`Welcome ${name}`);
    }
};
greet("Kajal");
greet("Kajal", 34);
