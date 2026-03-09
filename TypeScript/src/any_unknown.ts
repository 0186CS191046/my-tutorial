// let variable:any = 5  // disable type checking
// variable = "kajal"

// console.log(variable);


// let variable : unknown;

// variable = 10;
// // variable = "Kajal"

// console.log(variable);
// if(typeof variable == "string"){
//     variable += " Kumari"
// }else if (typeof variable == "number"){
// variable = variable + 14
// }

// console.log(variable);
type Post = {
    userId : number,
    id : number,
    title : string,
    body:Text
}
async function fetchData():Promise<Post[]> {
    const response = await fetch("https://jsonplaceholder.typicode.com/posts")
    const data : Post[] = await response.json();
    return data;
}

async function processData() {
    const response = await fetchData();
console.log(response);

    response.map((item : Post)=>{
        console.log(item.title);
        
    })

}

processData()