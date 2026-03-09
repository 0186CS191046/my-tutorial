// class Personss {
//     constructor(
//         public name: string,
//         public age: number,
//         private hobbies: string[]) {
//         if (this.age > 150 || this.age < 0) {
//             throw new Error(`Age is invalid!`)
//         }
//     }
//     introduceParent(): string {
//         return `Hello , My name is ${this.name}, My age is ${this.age} , My hobbies are ${this.hobbies.join(",")}` //private, we can access only this class
//     }
// }
// const pa = new Personss("Kajal", 34, ["reading", "painting"])
// pa.age = 152;
// console.log(pa.introduceParent());
// class Personss {
//     private _age: number|undefined = undefined;
//     constructor(
//         public name: string,
//         private hobbies: string[]) {
//     }
//     public set ages(age: number) {
//         if (age > 150 || age < 0) {
//             throw new Error(`Age is invalid!`)
//         }
//         this._age = age
//     }
//     public get ages(){
//         if(this._age===undefined){
//             throw new Error (`Age is not defined`)
//         }
//         return this._age
//     }
//     introduceParent(): string {
//         return `Hello , My name is ${this.name}, My age is ${this._age} , My hobbies are ${this.hobbies.join(",")}` //private, we can access only this class
//     }
// }
// const pa = new Personss("Kajal", ["reading", "painting"])
// pa.ages = 23
// pa.ages = 34
// console.log(pa.introduceParent(),pa.ages); //to get direct access to ages we want to define getter method
// Practice--------
// class BankAccount{
//     private _balance : number =0;
//     public get currBalance(){
//         return this._balance
//     }
//     public set currBalance(bal:number){
//         if(bal <= 0){
//             throw new Error(`Invalid balance!`)
//         }
//         this._balance = bal
//     }
// }
// const bank1 = new BankAccount();
// console.log(bank1.currBalance)
// bank1.currBalance = 7
// console.log(bank1.currBalance)
class Temperature {
    constructor() {
        this._celcius = 0;
    }
    get tempInCelcius() {
        return this._celcius;
    }
    set tempInCelcius(tem) {
        this._celcius = tem;
    }
    get fohrenheit() {
        return (this._celcius * 9 / 5) + 32;
    }
    set fohrenheit(f) {
        this._celcius = (f - 32) * 5 / 9;
    }
}
const t1 = new Temperature();
t1.tempInCelcius = 25;
console.log(t1.fohrenheit);
t1.fohrenheit = 77;
console.log(t1.tempInCelcius);
