#include <iostream>
#include <vector>
using namespace std;

// ----recursive approach----------
// iterative and  optimal approachis binary search which is in leetcode.
int bS(vector <int> &nums,int target,int st,int end){
    if(st<=end){
         int mid = st + (end-st) / 2;
    if(nums[mid] == target){
        return mid;
    }else if(nums[mid] > target){
        return bS(nums,target,st,mid-1);
    }else{
        return bS(nums,target,mid+1,end);
    }
    }
   return -1;
}

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 20;
    cout << bS(nums,target,0,nums.size()-1) << endl;
    return 0;
}