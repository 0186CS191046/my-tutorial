#include <iostream>
using namespace std;

// function declaration
// void printHello(){  // void means it not returning anything
//     cout << "hello world!";
// }

// int returnInt(){  // void means it not returning anything
//     cout << "hello world!" << endl;
//     return 3;
// }

// sum of two numbers
int add(int a, int b){   // a and b are parameters, where this function calls it takes value and create copy of that value
    return a+b;
}

// sum of two double numbers
double add2(double a, double b){
    return a+b;
}

// min of two numbers
int minimum(int a, int b){
    if(a<b) return a;
    else return b;
}

// find sum of 1 to n numbers
int sumN(int n){
    int s = 0,j=1;
    while(j<=n){
        s+=j;
        j++;
    }
    return s;
}

// find factorial of a number
int factorial(int n){
    int p = 1, j=1;
    while(j<=n){
        p*=j;
        j++;
    }
    return p;
}

// calculate sum of digits
int sumDigit(int n){
    int s = 0;
    while(n!=0){
        s += n%10;
        n = n/10;
    }
    return s;
}

// calculate nCr binomial coefficient for n & r
int facto(int n){
    int p=1,j=1;
    while(j<=n){
        p*=j;
        j++;
    }
    return p;
}
int binomial(int n,int r){
    return facto(n)/(facto(r)*facto(n-r));
}

// check a number is prime or not
bool prime(int n){
    if(n<=1) return false;
   
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) {
            return false;
        };
    }
    return true;
}

// print 1 to n prime numbers
void printPrime(int n){
    for(int i=1;i<=n;i++){
        if(i<=1) continue;
        bool isBool = true;

        for(int j=2;j*j <= i;j++){
            if(i%j == 0){
                isBool = false;
                break;
            }
        }
        if(isBool) cout << i << " " ;
       
    }
}

// find nth fibonicci number;
int fibon(int n){
    int first = 0;
    int second = 1;
    int i = 2,sum = 0;
    if(n<0) return 0;
    else if(n == 0 ||n==1) return 1;
    else{
        // cout << n << "-" << i << endl;
        while( i< n){
            sum = first+second;
            first = second;
            second = sum;
            // cout << first << " " << second <<endl;
            i++;
        }
    }
    return sum;
}

int main(){
    int a = 10;
    // printHello();   //function call / invoke

    // int val = returnInt();
    // cout << val;

    // int sadd = add(4,9);
    // cout << "Sum is :" << sadd;

    // double sadd2 = add2(4.9,9.9);
    // cout << "Sum is :" << sadd2;

    // cout << minimum(4,1) << endl;

    // cout << sumN(5) <<endl;

    // cout << factorial(6) <<endl;

    // cout << sumDigit(999999) <<endl;

    // cout << binomial(8,3);

    // cout << prime(5) <<endl;
    // cout << prime(9) <<endl;
    // cout << prime(20) <<endl;
    // cout << prime(17) <<endl;

    // printPrime(100);

    cout << (fibon(3)) << endl;
    cout << (fibon(8)) << endl;
    cout << (fibon(5)) << endl;
    cout << (fibon(9)) << endl;

    return 0;
}