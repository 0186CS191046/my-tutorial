#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

// ------------------Three sum -------------
// Brute force approach - Time Complexity = O(n^3 * log(uniquetriplets)), Space Complexity = O(uniqueTriplets)
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> s;
    vector<vector <int>> ans;
    int n = nums.size();

    for(int i=0;i<n;i++){
        int first = nums[i];
        for(int j=i+1;j<n;j++){
            int second = nums[j];
            for(int k = j+1; k<n;k++){
                int third = nums[k];
                int sum = first+second+third;
                if(sum==0){
                    vector<int> trip;
                    trip.push_back(first);
                    trip.push_back(second);
                    trip.push_back(third);
                    sort(trip.begin(),trip.end());
                    if(s.find(trip) == s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                    
                }
            }
        }
    }
    return ans;
}

// Better approach - Time Complexity = O(n^2 log(uniqueTriplets)), Space Complexity = O(uniquetriplets + n)
vector<vector<int>> threeSumBetter(vector<int>& nums) {
    set<vector<int>> uniqueTriplets;
    int n = nums.size();

    for(int i=0;i<n;i++){
        int tar = -nums[i];   // -a
        set<int> s;
        for(int j=i+1;j<n;j++){
            int toFind = tar - nums[j] ; 
            if(s.find(toFind) != s.end()){
                vector<int> trip = {nums[i],nums[j],toFind};
                sort(trip.begin(),trip.end());
                uniqueTriplets.insert(trip);
            }
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(uniqueTriplets.begin(),uniqueTriplets.end());
    return ans;  
}

// Optimal approach - Time Complexity = O(n logn + n^2), Space Complexity = O(uniqueTriplets)
vector<vector<int>> threeSumOptimal(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=  nums.size();

    for(int i=0;i<n;i++){
        int first = nums[i];
        int j = i+1;
        int k = n-1;
        if(i>0 && first == nums[i-1]) continue;

        while(j<k){
            int sum = first + nums[j] + nums[k];
            if(sum > 0) k--;
            else if(sum < 0) j++;
            else{
                ans.push_back({first ,nums[j] , nums[k]});
                j++; k--;
                while(j<k && nums[j] == nums[j-1]) j++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,4};

    // Brute Force
    // vector<vector<int>> result = threeSum(nums);

    // Better Approach
    // vector<vector<int>> result = threeSumBetter(nums);

    // Optimal Approach
    vector<vector<int>>result  = threeSumOptimal(nums);

      for(auto val:result){
        for(int v : val){
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}