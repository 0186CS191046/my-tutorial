#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int st,int end,int mid){
    vector<int>temp;
    int i = st, j= mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
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
    for(int idx = 0;idx<temp.size();idx++){
        arr[idx+st] = temp[idx];
    }
}

vector<int> mergeArray(vector<int> &arr, int st, int end){
    if(arr.size()==1) {
        return arr;
    }
    int mid = st + (end-st)/2;

    if(st<end){
        mergeArray(arr,st,mid);
        mergeArray(arr,mid+1,end);
        merge(arr,st,end,mid);
    }
    return arr;
}

int main(){
    vector<int> arr = {2,9,3,6,8,3,1,0,4};
    mergeArray(arr,0,arr.size()-1);
    for(int val : arr){
        cout << val << " ";
    }
    return 0;
}