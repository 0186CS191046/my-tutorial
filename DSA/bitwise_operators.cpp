#include <iostream>
using namespace std;

// ------------bitwise operators
// using loop
// int power2(int n){
//     int power = 1;
//     while(power <= n){
//         int temp = 2*power;
//         if(temp == n ){
//             return true;
//         }
//         power = power*2;
//     }
//     return false;
// }

// without loop
// int power2(int n){
//     int count = 0;
//     while(n>0){
//         cout << "++++++++++" << count << "-----" << (n&1) <<  endl ;
//         if(n & 1){
//             count ++;
//         }
//         n = n >> 1;
//         cout << "++2345678967" << count << "-----" << (count) << "_____" << n <<  endl ;
//     }
//     return count == 1;
// }

// reverse an integer

int reverseInt(int n){
    int ans = 0,power = 1;
    while(n>0){
        int rem = n%10;
        ans = ans*10 + rem;
        n = n/10;
    }
    return ans;
}

int main(){
    // int a = 4, b = 6;
    // cout<< (a|b)<<endl ;     // bitwise  |  operator
    // cout<< (a&b)<<endl ;     // bitwise  &  operator
    // cout<< (a^b)<<endl ;     // bitwise  ^  operator
    // cout<< (a<<2)<<endl ;     // bitwise  <<  operator  - left shift
    // cout<< (a>>2)<<endl ;     // bitwise  <<  operator  - right shift

    // operator precedence-----------------
    // cout << (5-2*5) << endl;
    // cout << ((5-2)*5) << endl;
    // cout << (4*5/5) << endl;

    // Data type  Modifiers-------------- change meaning of data-types
    // cout << (sizeof(int))<<endl;
    // cout << (sizeof(long int))<<endl;
    // cout << (sizeof(long long int))<<endl;
    // cout << (sizeof(short int))<<endl;

    // unsigned int n= -100;
    // cout << n << endl;

      // homework---------------
    // int a = 6, b = 10;
    // cout<< (a|b)<<endl ;   
    // cout<< (a&b)<<endl ;     
    // cout<< (a^b)<<endl ;     

    // int a = 10, b = 2;
    // cout<< (a << b) << endl ; 

    // int a = 10, b = 1;    
    // cout<< (a>>b)<<endl ;     

    // Figure out how to find is a number is power of 2 without any loop
    int n;
    cout << "Enter number : ";
    cin >> n;
    // cout << power2(n);

    // Write a function to reverse an integer
    cout << reverseInt(n) << endl;
    return 0;
}