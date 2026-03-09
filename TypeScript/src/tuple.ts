// type PersonInfo = [string,boolean,number];
// type PersonInfo2 = readonly [string,boolean,number];  //readonly

// const student:PersonInfo = ["Kajal",true,24]

// const student2 : PersonInfo = ["Kumari",false,34]
// console.log(student);
// console.log(student2);

// student.push(34);
// console.log(student);


// const displayInfo = (person:PersonInfo2)=>{
//     const [name,isDrivingLicense,age] = person;
//     console.log(`Name : ${name} , Age is :${age} and isDrivingLicense : ${isDrivingLicense ? "yes" : "no"}`);
// };

// displayInfo(student)
// displayInfo(student2)

// type ProductInfo = [string, number, number];

// const product1: ProductInfo = [
//     "Laptop",
//     45000,
//     1
// ]

// const product3: ProductInfo = [
//     "Charger",
//     3000,
//     1
// ]

// const displayProductInfo = (product:ProductInfo) :string=> {
//     const [name,price,quantity] = product;
//     return `Your Product is :${name}, price is ${price} and quantity is ${quantity}`
// }

// console.log(displayProductInfo(product1));
// console.log(displayProductInfo(product3));


// type StudentGrade = [string, number]

// const grades: StudentGrade[] = [["English", 5],
// ["Match", 4],
// ["Science", 7]
// ];

// const averageOfGrade = (s: StudentGrade[]) => {
//     let total = 0
//     for(let [sum,grade] of s){
//         total += grade
//     }
//     console.log(total);
//     return Number((total / s.length).toFixed(2))
// }

// console.log(averageOfGrade(grades));

type WeatherData = [string,number,string];

const weather:WeatherData[] = [["Bhatpar Rani" , 23,"Good"],["Gorakhpur",34,"Not Good"],["Deoria",20,"Average"]]

const displayWeather = (weather : WeatherData[]) :void=>{
    console.log("Temperatures in Different Cities :");
    
    return weather.forEach((we:WeatherData) =>{
        console.log(`City : ${we[0]}, Temperature(in celcius) : ${we[1]}, Condition : ${we[2]}`);
    } )
}

displayWeather(weather);
