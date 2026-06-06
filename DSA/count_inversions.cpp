#include<iostream>
#include<vector>
using namespace std;


int merge(vector<int> &arr,int st, int end, int mid){
    vector<int> temp;
        
    int i=st, j=mid+1;
    int count = 0;
    while(i<=mid && j<=end){
        if(arr[i]<= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            count += mid-i+1;
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
            temp.push_back(arr[j]);
            j++;
    }
        
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st] = temp[idx];
    }
    return count;
}
    
int divideArray(vector<int> &arr,int st, int end){
    if(st<end){
        int mid = st + (end-st)/2 ;
        int leftArr = divideArray(arr, st, mid);  // left
        int rightArr = divideArray(arr, mid+1, end);  // right
        int mergeBacktrack = merge(arr,st,end,mid);   // backtrack
        return leftArr + rightArr + mergeBacktrack;
    }
    return 0;
}
    
int inversionCount(vector<int> &arr) {
    // Code Here
    return divideArray(arr,0,arr.size()-1);
}

int main(){
   vector<int> arr = {2, 4, 1, 3, 5};
   cout << inversionCount(arr) << endl;
   return 0;
}