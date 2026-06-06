#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

// --------------------Prime numbers---------------
string prime(int n){
     for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            return "Non Prime";
        }
    }
    return "Prime";
}
// write prime numbers 2 to N.
void prime2ToN(int N){
    for(int j=2;j<=N;j++){
        bool isPrime = true;
        for(int i=2;i*i<=j;i++){
            if(j%i == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            cout << j << " ";
        }
    }
}

// Sieve of Eratosthenes
int primeCount(int N){
    vector<bool> isPrimeN(N+1,true) ;
    int count = 0;
    for(int i=2;i<N;i++){
        if(isPrimeN[i]){
            count++;
            for(int j=i*2;j<=N;j+=i){
                isPrimeN[j] = false;
            }
        }
    }
    return count;
}

// -------------------Digit in numbers------------------
int digitCount(int n){
    int count = 0;
    while(n!=0){
        count++;
        n = n/10;
    }
    return count;
}

int sumOfDigit(int n){
    int sum = 0;
    while(n!=0){
        sum += n%10;
        n = n/10;
    }
    return sum;
}

// -----------------Armstrong Number
bool armstrongNumber(int n){
    int temp = n;
    int sum = 0;
    while(n!=0){
        int p = n%10;
        sum += (p*p*p);
        n = n/10;
    }
    if(sum==temp){
        return true;
    }
    return false;
}

// ------------GCD(Greatest Common Divisor) or HCF
// approach-1
int gcd(int n1, int n2){
    if(n1==0) return n2;
    if(n2==0) return n1;
    int gcd = 1;
    for(int i=2;i<=min(n1,n2);i++){
        if(n1%i == 0 && n2%i == 0){
            gcd = i;
        }
    }
    return gcd;
}

// approach-2 - Euclid's Algorithm
int gcd2(int n1, int n2){
    int gcd = 1;
    while(n1 > 0 &&  n2 > 0){
        if(n1>n2){
            n1 = n1%n2;
        }else{
            n2 = n2%n1;
        }
    }
    if(n1==0) return n2;
    return n1;
}

// using recursion
int gcdRec(int n1, int n2){  
    if(n2==0) return n1;
    return gcdRec(n2,n1%n2);  // we are assuming n1 is greater than b
}

// ----------------LCM(Lowest Common Multiplication)-------------
int lcm(int n1,int n2){
    int gcd = gcdRec(n1,n2);
    return (n1*n2)/gcd;
}

// -------------Reverse a number-------------
int reverseNumber(int n){
    int reverse = 0;
    while(n!=0){
        int remainder = n%10;
        reverse = reverse*10 + remainder;
        n = n/10;
    }
    return reverse;
}

int main(){
    // -------------prime numbers
    // int n;
    // cout << "Enter the number : ";
    // cin >> n;
    // cout << prime(n) << endl;
    // prime2ToN(n);

    // -------------digits in number
    // int n;
    // cout << "Enter the number : ";
    // cin >> n;
    // cout << digitCount(n) << endl;
    // cout << (int)(log10(n)+1) <<endl;  // It also returns count of digit
    // cout << sumOfDigit(n) << endl;

    // ------------Armstrong Number
    // int n;
    // cout << "Enter the number : ";
    // cin >> n;
    // cout << armstrongNumber(n) << endl;

    // -------------GCD or LCM-------------
    // int n1,n2;
    // cout << "Enter the numbers : ";
    // cin >> n1;
    // cin >> n2;
    // cout << gcd(n1,n2) << endl;
    // cout << gcd2(n1,n2) << endl;
    // cout << gcdRec(n1,n2) << endl;
    // cout << lcm(n1,n2) << endl;

    // ----------------Reverse number-------------
    int n;
    cout << "Enter Number : " ;
    cin >> n;

    cout << reverseNumber(n) << endl;

    return 0;
}