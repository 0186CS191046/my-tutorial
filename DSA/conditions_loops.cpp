#include <iostream>
using namespace std;

int main(){
    // ------------------------condition statements----------------------
    // n is positive or negative - if else
    // int n = -23;
    // if(n>=0){
    //     cout << "n is positive number";
    // }else{
    //     cout << "n is negative number";
    // }

    // can vote or not
    // int age = 13;
    // if(age>=18){
    //     cout << "Can vote";
    // }else{
    //     cout << "Can not vote";
    // }

    // using cin
    // int age = 13;
    // cout << "Enter your age : ";
    // cin >> age;
    // if(age>=18){
    //     cout << "Can vote" <<endl;
    // }else{
    //     cout << "Can not vote" << endl;
    // }

    // even or add number
    // int num;
    // cout << "Enter number : ";
    // cin >> num;
    // if(num%2 == 0){
    //     cout << "Even" << endl;
    // }else{
    //     cout << "Odd" <<endl;
    // }

    // Grade based on marks - if-else if-else
    // int marks;
    // cout << "Enter marks : ";
    // cin >> marks;

    // if(marks >=90){
    //     cout << "Grade is 'A'";
    // }else if(marks >=80 && marks<90){
    //     cout << "Grade is 'B'";
    // }else{
    //     cout << "Grade is 'C'";
    // }

    // find character is lowercase or uppercase
    // char ch;
    // cout << "Enter character :" ;
    // cin >> ch;

    // method-1
    // if(ch >='a' && ch <='z'){
    //     cout << "Lowercase" <<endl;
    // }
    // else{
    //     cout << "Uppercase" << endl;
    // }

    // method-2
    // if(ch >=65 && ch<=90){
    //     cout << "Uppercase" << endl;
    // }else{
    //     cout << "Lowercase" << endl;
    // }

    // ternary operator
    // cout << (ch>=65 && ch<=90 ? "Uppercase" : "Lowercase") <<endl;

    // -----------------------------Loops----------------
    // print number 1 to n - while
    // int n ,i=1;
    // cout << "Enter number :";
    // cin >> n ;

    // while(i<=n){
    //     cout << i << " " ;
    //     i++;
    // }

    // ------for-loop--------
    // // print 1 to n numbers
    // int n;
    // cout << "Enter the number : " ;
    // cin >> n;
    
    // for(int i=1;i<=n;i+=2){
    //     cout << i << " ";
    // }

    // sum of n numbers
    // int n,sum=0;
    // cout << "Enter the number : " ;
    // cin >> n;

    // for(int i=1;i<=n;i++){
    //     sum += i;
    // }
    // cout << "Sum of " << n << " is :" << sum <<endl;

    // Sum of odd numbers from 1 to n
    // using for-loop
    // int n,sum=0;
    // cout << "Enter the number : " ;
    // cin >> n;

    // for(int i=1;i<=n;i+=2){
    //     sum += i;
    // }
    // cout << "Sum of " << n << " is :" << sum <<endl;

    // using while loop
    //     int n, i=1,sum=0;
    //     cout << "Enter the number : " ;
    //     cin >> n;

    //    while(i<n){
    //         sum += i;
    //         i+=2;
    //     }
    //     cout << "Sum of " << n << " is :" << sum <<endl;

    // sum of even numbers
    // using for-loop
    // int n, i=1,sum=0;
    // cout << "Enter the number : " ;
    // cin >> n;

    // for(int i=0;i<=n;i++){
    //     if(i%2 == 0 ){
    //     sum += i;
    //     }
    // }
    // cout << "Sum of " << n << " is :" << sum <<endl;
    // using while-loop
    // int n, i=0,sum=0;
    //     cout << "Enter the number : " ;
    //     cin >> n;

    //    while(i<n){
    //         sum += i;
    //         i+=2;
    //     }
    //     cout << "Sum of " << n << " is :" << sum <<endl;

    // do-while loop - run minimum one time whether condition is true or false
    // do{
    //     cout << "Hello world!";
    // }while(i<5);

    // check if a number is prime or non-prime
    // int n;
    // cout << "Enter number : ";
    // cin >> n;
    // bool isPrime = true;
    // for(int i=2;i*i<n;i++){
    //    cout << "___" << i <<" " << i*i <<endl;
    //     if(n%i == 0 ){
    //         isPrime = false;
    //         break;
    //     }
    // }
    // if(isPrime){
    //     cout << n << " is a prime number" << endl;
    // }else{
    //     cout << n << " is not a prime number" << endl;
    // }

    // nested loops
    // int m,n;
    // cout << "Enter row : " ;
    // cin >> m;
    // cout << "Enter column : " ;
    // cin >> n;
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout << "* " ;
    //     }
    //     cout << endl;
    // }

    // sum of all numbers from 1 to n which is divisible by 3
    // using for-loop
    // int n,sum=0;
    // cout << "Enter n :";
    // cin >> n;
    // for(int i=0 ;i<=n;i++){
    //     if (i%3 == 0){
    //         sum += i;
    //     }
    // }
    // cout << "Sum is : " << sum;

    // using while-loop
    // int i=0,n,sum=0;
    // cout << "Enter n :";
    // cin >> n;
    // while(i<=n){
    //     if (i%3 == 0){
    //         sum += i;
    //     }
    //     i++;
    // }
    // cout << "Sum is : " << sum;

    // print factorial of a number n.
    int n,product=1;
    cout << "Enter n :";
    cin >> n;
    for(int i=1 ;i<=n;i++){
            product *= i;
    }
    cout << "Factorial is : " << product;
}