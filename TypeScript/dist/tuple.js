// type PersonInfo = [string,boolean,number];
// type PersonInfo2 = readonly [string,boolean,number];  //readonly
const weather = [["Bhatpar Rani", 23, "Good"], ["Gorakhpur", 34, "Not Good"], ["Deoria", 20, "Average"]];
const displayWeather = (weather) => {
    console.log("Temperatures in Different Cities :");
    return weather.forEach((we) => {
        console.log(`City : ${we[0]}, Temperature(in celcius) : ${we[1]}, Condition : ${we[2]}`);
    });
};
displayWeather(weather);
