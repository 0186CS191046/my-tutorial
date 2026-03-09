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

abstract class Shape{
    constructor(protected color : string){}
    abstract calculateArea():number;
    abstract displayArea():void;
}

class Circle extends Shape{
    constructor(public radius:number, protected color:string){
        super(color)
    }

    public calculateArea(): number {
        return Math.PI*this.radius*this.radius
    }

    public displayArea(): void {
        console.log(`This is a ${this.color} circle with radius ${this.radius} and area is ${this.calculateArea()}`);
        
    }
}

const circ = new Circle(7,"red")
console.log(circ.calculateArea());
circ.displayArea();


class Rectangle extends Shape{
    constructor(protected width:number,protected height:number,protected color:string){
        super(color)
    }

    public calculateArea(): number {
        return this.width*this.height
    }

    public displayArea(): void {
        console.log(`This is a ${this.color} rectangle with width ${this.width}, height ${this.height} and area is ${this.calculateArea()}`);
    }
}

const rect = new Rectangle(3,6,"white");
console.log(rect.calculateArea());
rect.displayArea();

class Square extends Shape{
    constructor(protected length:number,protected color:string){
        super(color)
    }

    public calculateArea(): number {
        return this.length*this.length
    }

    public displayArea(): void {
        console.log(`This is a ${this.color} square with length ${this.length}, and area is ${this.calculateArea()}`);
    }
}

const sq = new Square(3,"white");
console.log(sq.calculateArea());
sq.displayArea();