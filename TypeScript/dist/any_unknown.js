// let variable:any = 5  // disable type checking
// variable = "kajal"
async function fetchData() {
    const response = await fetch("https://jsonplaceholder.typicode.com/posts");
    const data = await response.json();
    return data;
}
async function processData() {
    const response = await fetchData();
    console.log(response);
    response.map((item) => {
        console.log(item.title);
    });
}
processData();
