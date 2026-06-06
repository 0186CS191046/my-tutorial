#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// Brute force approach
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    int n = nums.size();
    for(int i=0;i<n-k+1;i++){
        cout << "nums[i]" << nums[i] << endl;
        int temp = -1;
        for(int j=i;j<i+k;j++){
            cout << "___" << nums[i] << ">" << nums[j] << endl;
            temp = max(temp,nums[j]);
        }
        ans.push_back(temp);
    }
    return ans;
}

// Optimal approach
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;
    int n = nums.size();
    for(int i=0;i<k;i++){
        while(dq.size() > 0 && nums[i] > nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << "dq.push_bac " << dq.front() << endl;
    for(int i=k ;i<n ;i++){
        ans.push_back(nums[dq.front()]);
        while(dq.size() > 0 && dq.front() < (i-k+1) ){
            dq.pop_front();
        }

        // cout << "====" << i <<"-" << dq.back() << endl;
        while(dq.size() > 0 && nums[i] > nums[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);

    return ans;
}

int main(){
    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;
    vector<int> ans = maxSlidingWindow2(nums,k);
    for(auto val : ans){
        cout << val << " " ;
    }
    return 0;
}