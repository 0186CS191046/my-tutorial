// function isEven(num:number):Boolean{
//     return num%2==0
// }

// console.log(isEven(8))

// function divisibleBy4And8 (num:number):boolean {
//     return (num%4 ==0 && num%8 == 0)
// }

// console.log(divisibleBy4And8(9))

// const maxNumber = Number.MAX_SAFE_INTEGER
const maxNumber:bigint = 9007199254740991n
console.log(maxNumber)

const anotherBigNumber = 90071992547409916n
let sum : bigint = maxNumber + anotherBigNumber
console.log(sum)

const diff :bigint= anotherBigNumber-maxNumber
console.log(diff)

const multiplication = maxNumber*anotherBigNumber
console.log(multiplication);

const division = anotherBigNumber/maxNumber
console.log(division);
