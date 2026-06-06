#include<iostream>
using namespace std;

int subArrayEqualsK(vector<int>&nums,int k){
    int n = nums.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i+1;j<n;j++){
            sum += arr[j];
            if(sum == k) count ++;
        }
    }
    return count;
}

int main(){
    vector <int> nums = {1,1,1};
    int k = 2;

    cou
    return 0;
}