// interface User2 {
//     name: string,
//     age: number
// }

// const greet2 = (user: User2): string => {
//     return `Welcome ${user.name}, Is your age is ${user.age}?`
// }

// const us1:User2 = {
//     name:"Kajal",
//     age:23
// }

// console.log(greet2(us1));


interface Product2 {
name:string,
price:number,
quantity:number
}

const pr1:Product2 = {
name:"Laptop",
price:40000,
quantity:7
}

const totalPrice  = (product:Product2) :number=> {
    return product.price*product.quantity
}

console.log(totalPrice(pr1)
);
