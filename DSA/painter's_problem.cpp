// Given an array arr[] and an integer k, where the array represents the boards and each element denotes the length of a board, and k painters are available to paint these boards. Each unit length of a board takes 1 unit of time to paint. Find the minimum time required to paint all the boards such that each painter paints only contiguous sections of the array. A painter can paint boards like [2, 3, 4], [1], or even no board, but cannot paint non-contiguous boards like [2, 4, 5].

// Examples:

// Input: arr[] = [5, 10, 30, 20, 15], k = 3
// Output: 35
// Explanation: The most optimal way will be: Painter 1 allocation : [5,10], Painter 2 allocation : [30], Painter 3 allocation : [20, 15], Job will be done when all painters finish i.e. at time = max(5 + 10, 30, 20 + 15) = 35

// Input: arr[] = [10, 20, 30, 40], k = 2
// Output: 60
// Explanation: The most optimal way to paint: Painter 1 allocation : [10, 20, 30], Painter 2 allocation : [40], Job will be complete at time = 60

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>&nums,int k,int maxMinTime){
    int n = nums.size();
    int mintime = 0, painter = 1;
    for(int i=0;i<n;i++){
        if(nums[i]>maxMinTime) return false;
        else if((mintime+nums[i]) <= maxMinTime){
            mintime += nums[i];
        }else{
            painter++;
            mintime = nums[i];
        }
    }
    return painter<=k;
}

int paintersMinTime(vector<int>&nums,int k){
    int sum = 0,maximum = -1, n = nums.size();
    if(k>n) return -1;
    for(int val : nums){
        sum += val;
        maximum = max(maximum,val);
    }
    int st = maximum,end = sum, ans=-1;
    while(st<=end){
        int mid = st+(end-st)/2;
        cout << "--" << st <<"--" << end << "mid--"<< mid << endl;
        if(isPossible(nums,k,mid)){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;
        }
    } 
    return ans;
}

int main(){
    vector <int> nums = {5, 10, 30, 20, 15};
    int k= 3;
    cout << "--"  << endl;
    cout << paintersMinTime(nums,k) << endl;
    return 0;
}
