#include <iostream>
using namespace std;

int main(){
    int n=5;
    int arr[] = {1,2,3,4,5};

    int maxSum = INT_MIN;
    // print all possible subarrays
    // for(int i=0;i<n;i++){
    //     for(int j= i; j<n; j++){
    //         for(int k=i;k<=j;k++){
    //             cout << arr[k];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
       
    // }

    // max subarrays sum - > brute-force
    // for(int i=0;i<n;i++){
    //     int currSum = 0;
    //     for(int j= i; j<n; j++){
    //         currSum += arr[j];
    //         maxSum = max(maxSum,currSum);
    //     }
    // }
    
    // max subarrays sum  - > Kadane's Algorithm
    int currSum = 0;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        maxSum = max(maxSum,currSum);
        if(currSum<0){
            cs = 0
        }
    }

    cout << "Maximum sum is : " << maxSum;
    return 0;
}