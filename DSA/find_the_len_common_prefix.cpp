#include<iostream>
#include <vector>
#include <string> 
using namespace std;

int findLen(int num1, int num2){
    string st1 = to_string(num1);
    string st2 = to_string(num2);
    int len = 0, i=0, j=0;

    cout << "size : " << st1.size() <<"-" << st2.size()<<endl;
    while (i<st1.size() && j<st2.size()){
        if(st1[i]!=st2[j]){
            return len;
        }
        len++;
        i++; j++;
    }
    return len;
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    int maxLen = 0;
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            cout << arr1[i] << "-" << arr2[j] << endl;
            int tempCount = findLen(arr1[i],arr2[j]);
            maxLen = max(maxLen,tempCount);
        }
    }
    return maxLen;

}

bool check(vector<int>& nums) {
    int n = nums.size();
    int idx = -1;
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]) {
            idx = i;
            break;
        };
    }
    cout << "idx---" << idx << endl;
    if(idx != -1){
        int x = n-idx-1;
        while(x){
            int temp = nums[n-1];
            vector<int> B(n,-1);
            for(int j=0;j<n-1;j++){
                B[j+1] = nums[j];
                cout << "nums[j]--" << nums[j] << endl;
                // nums[j+1] = B[j+1];
            }
            B[0] = temp;
            nums = B;
            x--;
            cout << "A : is : " ;
            for(auto i : nums){
                cout << i << " ";
            }
            cout <<"\nB : is : " ;
            for(auto i : B){
                cout << i << " ";
            }
            cout << endl;
        }
        for(int k=0;k<n-1;k++){
            if(nums[k] > nums[k+1]) return false;
        }
    }
    return true;
}

int main(){
    // vector<int> arr1 = {1,2,3}, arr2 = {4,4,4};
    // cout << longestCommonPrefix(arr1,arr2) << endl;;
    // cout << findLen(234,789) << endl;
    vector<int> nums = {3,4,5,1,2};
    check(nums);
    return 0;
}
