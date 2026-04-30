#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pairSum(vector<int> nums, int target){
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
             if(nums[i]+nums[j] == target ){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
             }
        }
       
    }
    return ans;
}

vector<int> pairSum2(vector<int> nums, int target){
    vector<int> ans;
    int i=0,j=nums.size()-1;

   while(i<j){
    cout << "ans--" << i << " ------" << j <<endl;
    if(nums[i]+nums[j] == target){
        ans.push_back(i);
        ans.push_back(j);
        // cout << "ans--" << i << " ------" << j <<endl;
        return ans;
    }
    else if(nums[i]+nums[j] < target){
        i++;
    }else{
        j--;
    }
   }
    return ans;
}

int majorityElement(vector<int> nums){
    for(int i:nums){
        int freq = 0;
        for(int j :nums){
            if(i==j) freq++;
        }
        if(freq > nums.size()/2){
            return i;
        }
    }
    return -1;
}

int majorityElement2(vector<int> nums){
    sort(nums.begin(),nums.end());
    int freq = 1,ans = nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){ 
            freq++;
        }else{
            freq = 1;
            ans = nums[i];
        }
        if(freq > nums.size()/2){
            return ans;
        }
    }
    return -1;
}

int majorityElement3(vector<int> nums){
    int freq = 0,ans = 0;
    for(int i=0;i<nums.size();i++){
        if(freq == 0){
            ans = nums[i];
        }
        if( ans == nums[i]){
        freq++;
       }else{
        freq--;
       }
    }

    int count = 0;
    for(int i:nums){
        if(i==ans){
            count++
        }
    }

    if(count > nums.size()/2) return ans;
    else{
        return -1
    }
    return ans;
}

int main(){
    // --------------Pair sum - return pair in sorted array with target sum
    // vector<int> nums = {2,4,6,8,10,12};
    // int target = 14;

    // ---------Brute force
    // vector<int> ans = pairSum(nums,target);
    // cout << ans[0] << "," << ans[1] << endl;

    // optimized solution - two pointer approach
    // vector<int> nums = {2,3,6,8,10,12};
    // int target = 16;

    // Brute force
    // vector<int> ans = pairSum2(nums,target);
    // cout << ans[0] << "," << ans[1] << endl;

    // -------------Majority Element-------------------
    vector<int> nums = {2,2,1,1,1,2,2};

    // cout<<majorityElement(nums)<<endl;
    // cout<<majorityElement2(nums)<<endl;
    cout<<majorityElement3(nums)<<endl;

    return 0;

    // ------------Container With Most Water
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for(int i=0;i<height.size();i++){
            for(int j = i+1;j<height.size();j++){
                int heig = min(height[i],height[j]);
                int width = j-i;
                int currArea = width*heig;
                maxArea = max(maxArea,currArea);
            }
        }
        return maxArea;
    }
}