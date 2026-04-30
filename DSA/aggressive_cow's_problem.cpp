// You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples:

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows in this case is 3, which is the largest among all possible ways.

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>&arr,int k, int maxAllowedDitance){
    int cows = 1,lastStall=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]-lastStall >= maxAllowedDitance){
            cows++;
            lastStall = arr[i];
        }
        if(cows==k) return true;
    }
    return false;
}
int aggressCows(vector<int> &nums,int k){
    int n = nums.size();
    int mini = INT_MAX, maxi = INT_MIN;
    for(int val:nums){
        mini = min(mini,val);
        maxi = max(maxi,val);
    }
    int st = mini,end = maxi-mini,ans = -1;;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(isPossible(nums,k,mid)){
            ans = mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int> stalls= {1, 2, 4, 8, 9};
    int k = 3;

    cout << aggressCows(stalls,k) <<endl;
    return 0;
}