const getUserName = document.querySelector("#user");
const formElement = document.querySelector("#form");
const main_container = document.querySelector(".main_container");
console.log("formElement", formElement.value);
async function myCustomeFetcher(url, options) {
    const response = await fetch(url, options);
    if (!response.ok) {
        throw new Error(`Network response was not OK - status : ${response.status}`);
    }
    const data = await response.json();
    return data;
}
const showResultUI = (singleUser) => {
    main_container.insertAdjacentHTML("beforeend", `<div class="card">
        <img src="${singleUser.avatar_url}" alt = "${singleUser.login}">
        <div class="card-footer">
        <p style="color:white">${singleUser.login}</p>
        <img src="${singleUser.avatar_url}" alt = "${singleUser.login}">
        <a href="${singleUser.url}">Github</a>
        </div>
        </div>`);
};
async function fetchUserData(url) {
    myCustomeFetcher(url, {}).then((userInfo) => {
        for (const singleUserData of userInfo) {
            showResultUI(singleUserData);
        }
    });
}
fetchUserData("https://api.github.com/users");
formElement.addEventListener("submit", async (e) => {
    e.preventDefault();
    const searchELement = getUserName.value.toLocaleLowerCase();
    try {
        const url = "https://api.github.com/users";
        const allMatchingUserData = await myCustomeFetcher(url, {});
        const matchingData = allMatchingUserData.filter((user) => {
            return user.login.toLocaleLowerCase().includes(searchELement);
        });
        main_container.innerHTML = "";
        if (matchingData.length == 0) {
            main_container?.insertAdjacentHTML("beforeend", `<p class="empty-msg">No matching users fiund!</p>`);
        }
        else {
            for (const singleUser of matchingData) {
                showResultUI(singleUser);
            }
        }
    }
    catch (error) {
        console.log("Error------->:", error);
    }
});
export {};
