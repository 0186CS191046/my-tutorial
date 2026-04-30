#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &nums, int target){
    for(int i=0;i<nums.size();i++){
        if(nums[i] == target) {
            return i;
        }
    }
    return 0;
}

void reverseArray(vector<int>&nums){
    int i=0,j=nums.size()-1;
    while(i<j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
}

int main(){
    // ---------------------vectors syntax-------------
    // vector <int> vec;  // 0 size
    // cout << vec[0] << endl;

    // vector<int> vec = {1,3,5,7,8};   // 5 size
    // cout << vec[4] << endl;

    // vector<int>vec(3,0) ; // here 3 is the size of vectors and at every index 0 will be stored
    // cout << vec[0] << endl;
    // cout << vec[1] << endl;
    // cout << vec[2] << endl;

    // ----------------iteration in vector--------------
    // vector <int> vec = {2,4,6,8,1,3};
    // for(int i:vec){                 // here i represents value not index
    //     cout << i << endl;    
    // }

    // -----------------vector functions-----------------
    // vector<char> vec = {'a','b','c','d','e'};

    // cout << "size is : " << vec.size() << endl;              //size function
    // vec.push_back('f');            // push_back function
    // cout << "size is : " << vec.size() << endl;  
    // vec.pop_back();               
    // cout << "size is : " << vec.size() << endl;  
    // for(char i:vec){           
    //     cout << i << endl;    
    // }

    // cout << vec.front() << endl;  
    // cout << vec.back() << endl;  
    // cout << vec.at(2) << endl;  

    // --------------Static vs Dynamic Allocation-----------------
    // vector<int> vec;
    // vec.push_back(2);
    // vec.push_back(4);
    // vec.push_back(5);

    // cout << vec.size() << endl;
    // cout << vec.capacity() << endl;

    // ------------Homework------------
    // -----------Linear search on vectors
    // vector <int> vec = {2,4,7,2,6,8,6}; 
    // cout << linearSearch(vec,8) << endl;

    // -----------Reverse an array using vectors
    // vector <int> vec = {2,4,7,2,6,8,6}; 
    // reverseArray(vec);

    // for(int i:vec){
    //     cout << i << " ";
    // }
    // return 0;
}