const favHobbies = (hobby:string | string[]) : string[] | undefined=>{
    if(typeof hobby === "object" && Array.isArray(hobby)){
        return hobby.map((ele:string)=> ele )
    }else{
        console.log(hobby);
    }
}

favHobbies("Playing cricket");
console.log(favHobbies(["Playing cricket","basketball","reading"]));
