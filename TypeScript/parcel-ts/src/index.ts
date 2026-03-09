const formButton = document.querySelector(".clickMe") as HTMLButtonElement;
const bodyElement: HTMLElement = document.body

let isWhite: boolean = false;

formButton.addEventListener("click", ():void =>{
    console.log("clickeme",bodyElement);

    if (isWhite) {
        bodyElement.style.backgroundColor = ""
    }
    else {
        bodyElement.style.backgroundColor = "#C40070"
    }
    isWhite = !isWhite
});