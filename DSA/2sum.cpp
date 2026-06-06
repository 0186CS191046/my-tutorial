#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// ------------------Two sum -------------
// Brute force approach - O(n^2)
vector<int> twoSum(vector<int>& nums, int target) {
    vector <int> ans = {-1,-1};
    int n = nums.size();
    for(int i=0;i<n;i++){
        int first = nums[i];
        for(int j=i+1;j<n;j++){
            int second = nums[j];
            int sum = first+second;
            if( sum == target){
                ans[0] = i;
                ans[1] = j;
                break;
            }
        }
    }
    return ans;
}

// Better approach - O(n logn)
vector<int> twoSumBetter(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int st = 0, end = n-1;
    vector<int> ans = {-1,-1};
    while(st < end){
        int sum = nums[st] + nums[end];
        if(sum>target){
            end--;
        }else if (sum < target){
            st++;
        }
        else{
            ans[0] = st;
            ans[1] = end;
            break;
        }
    }
    return ans;
}

// Optimal approach - O(n)
vector<int> twoSumOptimal(vector<int>& nums, int target) {
    unordered_map<int,int> value;  // value , index will be store
    int n=  nums.size();
    vector<int> ans = {-1,-1};

    for(int i=0;i<n;i++){
        int first = nums[i];
        int second = target-first;     // first + second = target
        if(value.find(second) != value.end()){
            ans[0] = value[second];
            ans[1] = i;
            break;
        }
        
        value[first] = i;
    }
    return ans;
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 26;
    // Brute Force
    // vector <int> result = twoSum(nums,target);

    // Better Approach
    // vector <int> result = twoSumBetter(nums,target);

    // Optimal Approach
    vector <int> result = twoSumOptimal(nums,target);

    cout << result[0] << "," << result[1] << endl;
    return 0;
}