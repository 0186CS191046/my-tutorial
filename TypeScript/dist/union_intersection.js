// const inputValue:(value:string|number)=> string|number = (value:string|number):string|number => {return value}
const u1 = {
    id: 1,
    name: "Kajal",
    email: "kajal.kumari@ficode.com"
};
const acc = {
    accountId: 4567890345567,
    accountType: "Savings",
    balance: 30000
};
const combineUserAndAccount = ((user, account) => {
    return { ...user, ...account };
});
console.log(combineUserAndAccount(u1, acc));
