const formButton = document.querySelector(".clickMe");
const bodyElement = document.body;
let isWhite = false;
formButton.addEventListener("click", ()=>{
    console.log("clickeme", bodyElement);
    if (isWhite) bodyElement.style.backgroundColor = "";
    else bodyElement.style.backgroundColor = "#C40070";
    isWhite = !isWhite;
});

//# sourceMappingURL=parcel-ts.377278e2.js.map
