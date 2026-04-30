#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int>&nums){
    for(int i=0;i<nums.size()-1;i++){
        bool isSwap = false;
        for(int j=0;j<nums.size()-i-1;j++){
            if(nums[j+1]<nums[j]){
                swap(nums[j+1],nums[j]);
                isSwap = true;
            }
        }
        if(!isSwap) return nums;
    }
    return nums;
}

void selectionSort(vector<int>&nums){
    for(int i=0;i<nums.size()-1;i++){
        int smallestIndex = i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]<nums[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(nums[i],nums[smallestIndex]);
    }
}

void insertionSort(vector<int>&nums){
    for(int i=1;i<nums.size();i++){
        int curr = nums[i];
        int prev = i-1;
        while(nums[prev]>curr && prev>=0){
            cout << nums[prev+1] << "-" <<nums[prev] <<endl;
            nums[prev+1] = nums[prev];
            cout << nums[prev+1] << "-" <<nums[prev] <<endl;
            prev--  ;
        }
        cout << prev <<endl;
        nums[prev+1] = curr;      //placing the curr element in its correct position
    }
}

int main(){
    vector<int> arr = {4,1,5,10,20,15,2,3};
    // vector<int> arr = {1,2,3,4,6,8};
    // bubbleSort(arr);
    // selectionSort(arr);
    insertionSort(arr);
    for(int val:arr){
        cout << val <<" ";
    }
    cout << endl;
    return 0;
}

