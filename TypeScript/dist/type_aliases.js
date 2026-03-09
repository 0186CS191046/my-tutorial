// type Person = {
//     name: string,
//     age: number,
//     isWorking?: true
//     address: {
//         country: string,
//         city?: string
//     }
// }
const product2 = {
    name: "Watch",
    price: 3000,
    quantity: 4
};
console.log(product2.price);
const calculatePrice = ((product) => {
    return product.price * product.quantity;
});
console.log(calculatePrice(product2));
