const favHobbies = (hobby) => {
    if (typeof hobby === "object" && Array.isArray(hobby)) {
        return hobby.map((ele) => ele);
    }
    else {
        console.log(hobby);
    }
};
favHobbies("Playing cricket");
console.log(favHobbies(["Playing cricket", "basketball", "reading"]));
