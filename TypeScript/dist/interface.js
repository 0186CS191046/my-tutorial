// interface User2 {
//     name: string,
//     age: number
// }
const pr1 = {
    name: "Laptop",
    price: 40000,
    quantity: 7
};
const totalPrice = (product) => {
    return product.price * product.quantity;
};
console.log(totalPrice(pr1));
