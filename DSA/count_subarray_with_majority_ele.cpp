#include<iostream>
#include <vector>
#include<map>
using namespace std;

int countCommonEle(vector<int>& A, vector<int>& B){

    map<int,int> m;
    for(auto v:A){
        if(m.find(v) == m.end()){
            m.insert({v,1});
        }else{
            m[v] +=1;   
        }
    }
   
    int count = 0;
    for(auto v: B){
        if(m.find(v) != m.end()){
            count ++;
        }
    }
    return count;
}

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vector<int> ans;

    int count = 0;
    for(int i=1;i<=A.size();i++){
        vector<int> A1(A.begin(),A.begin() +i);
        vector<int> B1(B.begin(),B.begin() +i);

        // for(auto v : A1){
        //     cout << v << " " ;
        // }
        // cout << endl;

        int temp = countCommonEle(A1,B1);
        // count += temp;
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    vector<int> nums = {2,3,1};
    vector<int> nums2 = {3,1,2};
    // vector<vector<int>> ans;
    // vector<int> temp ;
    
    vector<int> ans = findThePrefixCommonArray(nums,nums2);

    
    for(auto val:ans){
        cout << val << ' ' ;
    }
    return 0;
};