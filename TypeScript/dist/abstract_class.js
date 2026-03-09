// interface Person2 {
//     name: string, age: number
// }
// const Person2: Person2 = {
//     name: "Kajal",
//     age: 24
// }
// const Person21: Person2= {
//     name: "Kumari",
//     age: 25
// }
// const Person22: Person2 = {
//     name: "Kajal Kumari",
//     age: 24
// }
class Shape {
    constructor(color) {
        this.color = color;
    }
}
class Circle extends Shape {
    constructor(radius, color) {
        super(color);
        this.radius = radius;
        this.color = color;
    }
    calculateArea() {
        return Math.PI * this.radius * this.radius;
    }
    displayArea() {
        console.log(`This is a ${this.color} circle with radius ${this.radius} and area is ${this.calculateArea()}`);
    }
}
const circ = new Circle(7, "red");
console.log(circ.calculateArea());
circ.displayArea();
class Rectangle extends Shape {
    constructor(width, height, color) {
        super(color);
        this.width = width;
        this.height = height;
        this.color = color;
    }
    calculateArea() {
        return this.width * this.height;
    }
    displayArea() {
        console.log(`This is a ${this.color} rectangle with width ${this.width}, height ${this.height} and area is ${this.calculateArea()}`);
    }
}
const rect = new Rectangle(3, 6, "white");
console.log(rect.calculateArea());
rect.displayArea();
class Square extends Shape {
    constructor(length, color) {
        super(color);
        this.length = length;
        this.color = color;
    }
    calculateArea() {
        return this.length * this.length;
    }
    displayArea() {
        console.log(`This is a ${this.color} square with length ${this.length}, and area is ${this.calculateArea()}`);
    }
}
const sq = new Square(3, "white");
console.log(sq.calculateArea());
sq.displayArea();
