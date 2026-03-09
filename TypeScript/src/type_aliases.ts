// type Person = {
//     name: string,
//     age: number,
//     isWorking?: true
//     address: {
//         country: string,
//         city?: string
//     }
// }

// const student1: Person = {
//     name: "Kajal",
//     age: 24,
//     address: {
//         country: "India"
//     }
// }

// console.log(student1.address.country);

type Product = {
    name: string,
    price: number,
    quantity: number
}

const product2: Product = {
    name: "Watch",
    price: 3000,
    quantity: 4
}

console.log(product2.price);

const calculatePrice = ((product:Product)=> {
    return product.price * product.quantity
})

console.log(calculatePrice(product2));
