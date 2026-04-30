#include <iostream>
using namespace std;

// converssion decimal to binary
int decimalToBinary(int n){
    int ans = 0, power = 1;    // 10^0
    while(n!=0){
        int rem = n%2;
        n = n/2;
        ans += rem*power;
        power = power*10;
    }
    return ans;
}

// conversion binary to decimal
int binaryToDecimal(int n){
    int ans = 0, power = 1;    //2^0
    while(n!=0){
        int rem = n%10;
        n = n/10;
        ans += rem*power;
        power = power*2;
    }
    return ans;
}

int main(){
    // cout << decimalToBinary(5)<<endl;
    // cout << decimalToBinary(10)<<endl;

    cout << binaryToDecimal(1010)<<endl;
    cout << binaryToDecimal(110010)<<endl;
    return 0;
}