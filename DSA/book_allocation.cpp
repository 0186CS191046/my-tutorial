// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// All books must be allocated.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2

#include<iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &nums, int n, int m, int maxAllowedpages){
    int stu = 1,pages = 0;
    for(int i=0;i<n;i++){
        if(nums[i] > maxAllowedpages) return false;
        else if(nums[i]+pages<=maxAllowedpages){
            pages += nums[i];
        }else{
            stu++;
            pages = nums[i];
        }
    }
    return stu > m ? false : true;
}

int bookAlloc(vector<int> &nums, int n, int m){
    if(m>n) return -1;
    int sum = 0;
    for(int val:nums){
        sum+= val;
    }
    int st = 0,end = sum,ans = -1;

    while(st<=end){
        int mid = st + (end-st)/2;
        if(isValid(nums, n ,m ,mid)){  //left
            ans = mid;
            end = mid-1;
        }else{   //right
            st = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2,1,3,4};
    int n = 4;  //size of arr
    int m = 2;  // students
    cout << bookAlloc(arr,n,m)<<endl;
    return 0;
}
