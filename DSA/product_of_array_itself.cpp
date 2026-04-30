#include <iostream>
#include <vector>
using namespace std;

vector<int> productArr(vector<int>&arr){
    int prod = 1;
    for(int val:arr){
        prod *= val;
    }

    for(int i=0;i<arr.size();i++){
        arr[i] = prod/arr[i];
    }
    return arr;
}

vector<int> productArr2(vector<int> arr){
    vector<int> ans(arr.size(),1);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            if(i!=j){
                ans[i] *= arr[j];
            }
        }
    }
    return ans;
}

vector<int> productArr3(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n,1);
    vector<int>prefix(n,1);
    vector<int>suffix(n,1);

    for(int i=1;i<arr.size();i++){
        prefix[i] *=  prefix[i-1] * arr[i-1]; 
    }
    for(int i=n-2;i>=0;i--){
        suffix[i] *= suffix[i+1] * arr[i+1]; 
    }

    for(int i=0;i<n;i++){
        ans[i] = prefix[i] * suffix[i]; 
    }

    return ans;
}

vector<int> productArr4(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n,1);

    for(int i=1;i<n;i++){
        ans[i] =  ans[i-1] * arr[i-1]; 
    }

    int suffix = 1;
    for(int i=n-2;i>=0;i--){
        suffix = suffix * arr[i+1] ;
        ans[i] *= suffix;
    }

    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    //----------- using division operator
    // vector<int> arr2 = productArr(arr);

    // for(int i=0;i<arr2.size();i++){
    //     cout << arr2[i] << endl;
    // }
    
    // --------not using division operator
    // vector<int> arr2 = productArr2(arr);
    // vector<int> arr2 = productArr3(arr);
    vector<int> arr2 = productArr4(arr);
    for(int i=0;i<arr2.size();i++){
        cout << arr2[i] << endl;
    }

    return 0;
}