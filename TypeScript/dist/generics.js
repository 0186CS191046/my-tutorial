// function logAndReturn(value:number|string|boolean) : number|string|boolean {
// return value
// }
// const numberResult : number|string|boolean = logAndReturn(45);
// const stringResult :number|string|boolean = logAndReturn("Kajal");
// const booleaanResult :number|string|boolean= logAndReturn(true)
// console.log(numberResult);
// console.log(stringResult);
// console.log(booleaanResult);
// function logAndReturn<T>(value:T) :T{
// return value
// }
// const numberResult : number = logAndReturn(45);
// const stringResult : string = logAndReturn("Kajal");
// const booleaanResult :boolean= logAndReturn(true)
// console.log(numberResult);
// console.log(stringResult);
// console.log(booleaanResult);
// function add(a:number,b:number):number;
// function add(a:string,b:string):string;
// function add(a:any,b:any) : any{
//     return a+b
// }
// const result1:number = add(2,3)
// const result2 : string = add("Hello"," World!")
// console.log(result1);
// console.log(result2);
// function add<T>(a: T, b: T):void {
//     console.log(typeof a);
//     console.log(typeof b);    
// }
// const result1: void = add(4, 7)
// const result2: void = add("Hello", " World!")
// console.log(result1);
// console.log(result2);
function add(a, b, c) {
    console.log(typeof a);
    console.log(typeof b);
    console.log(typeof c);
}
const result1 = add(4, "hello", true);
const result2 = add("Hello", 4, false);
console.log(result1);
console.log(result2);
