class Temperature1 {
    static add(num1, num2) {
        return (num1 + num2);
    }
    static sub(num1, num2) {
        return (num1 - num2);
    }
    static division(num1, num2) {
        return (num1 / num2);
    }
    static modulus(num1, num2) {
        return (num1 % num2);
    }
    static mul(num1, num2) {
        return (num1 * num2);
    }
}
Temperature1.PI = Math.PI;
console.log(Temperature1.PI);
console.log(Temperature1.add(2, 6));
console.log(Temperature1.sub(7, 6));
console.log(Temperature1.mul(2, 6));
console.log(Temperature1.division(9, 6));
console.log(Temperature1.modulus(7, 6));
