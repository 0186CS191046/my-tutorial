class Temperature1{
    public static PI :number = Math.PI;

    public static add(num1:number,num2:number):number{
        return (num1+num2)
    }

    public static sub(num1:number,num2:number):number{
        return (num1-num2)
    }

    public static division(num1:number,num2:number):number{
        return (num1/num2)
    }

    public static modulus(num1:number,num2:number):number{
        return (num1%num2)
    }

    public static mul(num1:number,num2:number):number{
        return (num1*num2)
    }


}

console.log(Temperature1.PI);
console.log(Temperature1.add(2,6));
console.log(Temperature1.sub(7,6));
console.log(Temperature1.mul(2,6));
console.log(Temperature1.division(9,6));
console.log(Temperature1.modulus(7,6));