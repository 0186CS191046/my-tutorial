#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

// ------------------Four sum -------------
// Brute force approach - Time Complexity = O(n^4 * log(uniqueQuad)), Space Complexity = O(uniqueQuad)
vector<vector<int>> fourSum(vector<int>& nums) {
    set<vector<int>> s;
    vector<vector <int>> ans;
    int n = nums.size();

    for(int i=0;i<n;i++){
        int first = nums[i];
        for(int j=i+1;j<n;j++){
            int second = nums[j];
            for(int k = j+1; k<n;k++){
                int third = nums[k];
                for(int l = k+1;l<n;l++){
                    int fourth = nums[l];
                    int sum = first+second+third+fourth;
                    if(sum==0){
                        vector<int> trip = {first,second,third,fourth};
                        sort(trip.begin(),trip.end());
                        if(s.find(trip) == s.end()){
                            s.insert(trip);
                            ans.push_back(trip);
                        }      
                    }
                }
            }
        }
    }
    return ans;
}

// Better approach - Time Complexity = O(n^3 log(uniqueQuad)), Space Complexity = O(uniqueQuad + n)
vector<vector<int>> fourSumBetter(vector<int>& nums,int target) {
    set<vector<int>> uniqueQuad;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> s;
            for(int k= j+1;k<n;k++){
                int toFind = target -(nums[i] + nums[j] + nums[k]);

                if(s.find(toFind) != s.end()){
                vector<int> quad = {nums[i],nums[j],nums[k], toFind};
                sort(quad.begin(),quad.end());
                uniqueQuad.insert(quad);
            }
            s.insert(nums[k]);
            } 
            
        }
    }
    vector<vector<int>> ans(uniqueQuad.begin(),uniqueQuad.end());
    return ans;  
}

// Optimal approach - Time Complexity = O(n logn + n^3), Space Complexity = O(uniqueQuad)
vector<vector<int>> fourSumOptimal(vector<int>& nums,int target) {
    sort(nums.begin(),nums.end());
    int n=  nums.size();
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            int p = j+1;
            int q = n-1;

            while(p<q){
            long long sum = (long long) nums[i] + (long long )nums[j] + (long long )nums[p] + (long long ) nums[q];
            if(sum > 0) q--;
            else if(sum < 0) p++;
            else{
                ans.push_back({nums[i] ,nums[j] , nums[p] , nums[q]});
                p++; q--;
                while(p<q && nums[p] == nums[p-1]) p++;
            }
        }
        }    
    }
    return ans;
}

int main(){
    vector<int> nums = {2,2,2,2,2,2};
// -1 0 0 1 
// -2 -1 1 2 
// -2 0 0 2 

    // Brute Force
    // vector<vector<int>> result = fourSum(nums);

    // Better Approach
    // vector<vector<int>> result = fourSumBetter(nums,0);

    // Optimal Approach
    vector<vector<int>>result  = fourSumOptimal(nums,0);

      for(auto val:result){
        for(int v : val){
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}