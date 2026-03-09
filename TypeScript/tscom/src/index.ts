const getUserName = document.querySelector("#user") as HTMLInputElement;
const formElement = document.querySelector("#form") as HTMLFormElement;
const main_container = document.querySelector(".main_container") as HTMLElement;

console.log("formElement",formElement.value);

interface UserData {
    id: number;
    avatar_url: string;
    login: string,
    url: string
}

async function myCustomeFetcher<T>(url: string, options?: RequestInit): Promise<T> {
    const response = await fetch(url, options);
    if (!response.ok) {
        throw new Error(`Network response was not OK - status : ${response.status}`)
    }

    const data = await response.json();
    return data
}

const showResultUI = (singleUser: UserData) => {
    main_container.insertAdjacentHTML("beforeend",
        `<div class="card">
        <img src="${singleUser.avatar_url}" alt = "${singleUser.login}">
        <div class="card-footer">
        <p style="color:white">${singleUser.login}</p>
        <img src="${singleUser.avatar_url}" alt = "${singleUser.login}">
        <a href="${singleUser.url}">Github</a>
        </div>
        </div>`)
}

async function fetchUserData(url: string) {
    myCustomeFetcher<UserData[]>(url, {}).then((userInfo) => {
        for (const singleUserData of userInfo) {
            showResultUI(singleUserData)
        }
    })


}

fetchUserData("https://api.github.com/users");

formElement.addEventListener("submit", async (e) => {
    e.preventDefault();

    const searchELement = getUserName.value.toLocaleLowerCase();

    try {
        const url = "https://api.github.com/users";
        const allMatchingUserData = await myCustomeFetcher<UserData[]>(url, {});

        const matchingData = allMatchingUserData.filter((user) => {
            return user.login.toLocaleLowerCase().includes(searchELement)
        });

        main_container.innerHTML = "";
        if (matchingData.length == 0) {
            main_container?.insertAdjacentHTML("beforeend", `<p class="empty-msg">No matching users fiund!</p>`)
        } else {
            for (const singleUser of matchingData) {
                showResultUI(singleUser)
            }
        }

    } catch (error) {
        console.log("Error------->:", error);
    }
})