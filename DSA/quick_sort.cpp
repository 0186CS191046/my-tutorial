#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int idx = low-1, pivot = arr[high];
    for(int i=low;i<high;i++){
        if(arr[i]<= pivot){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx],arr[high]);
    return idx;
}

void quickSort(vector<int>& arr, int low, int high) {
    // code here
    if(low< high){
        int pivIdx = partition(arr,low,high);
        quickSort(arr,low,pivIdx-1);     // left half
        quickSort(arr,pivIdx+1,high);    // right half
    }
}



int main(){
    vector<int> arr = {2,4,5,1,9,7,4,0,1,2,6};
    quickSort(arr,0,arr.size()-1);

    for(int val : arr){
        cout << val << " ";
    }

    return 0;
}
