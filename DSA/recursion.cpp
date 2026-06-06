#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printNum(int n){
    cout << n << " ";
    if(n==1){
        return;
    }
    printNum(n-1);
}

int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}

int sumOfNum(int n){
    if(n==1){
        return 1;
    }
    return n + sumOfNum(n-1);
}

int fibonicci(int n){
    if(n==0 || n==1) return n;
    return fibonicci(n-1) + fibonicci(n-2);
}

bool isSorted(vector<int> &nums,int n){
    if(n==0 || n==1){
        return true;
    }
    return nums[n-1] >= nums[n-2] && isSorted(nums, n-1) ;
}

void printAllSubsets(vector<int>&nums,vector<int>&ans,int i){
    if(i== nums.size()){
        for(int val:ans){
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(nums[i]);
    printAllSubsets(nums,ans,i+1);
    ans.pop_back();
    printAllSubsets(nums,ans,i+1);
}

// -------------------permutations in array
void getpermutations(vector<int>&nums, int i,vector<vector<int>>& ans){
    if(i == nums.size()){
        cout << "________________" << endl;
         for(int v : nums){
            cout << v << " ";
        }
        ans.push_back(nums);
        return;
    }
    for(int idx =i; idx<nums.size(); idx++){
        cout << "i-- : " << i << " idx : " << idx << endl;
        swap(nums[i],nums[idx]);
        getpermutations(nums,i+1,ans);
        cout << "++++++++++++++++" << idx << endl;
        swap(nums[i],nums[idx]);
    }
}

// -------------------permutations in string
void getpermutationsString(string &str,int idx, vector<string> &ans){
    if(idx==str.size()){
        ans.push_back(str);
        return;
    }
    for(int i=idx;i<str.size();i++){
        swap(str[i],str[idx]);
        getpermutationsString(str,idx+1,ans);
        swap(str[i],str[idx]);
    }
}


bool isSafe(vector<string> &board, int row, int col, int n){
        // horizontal check
        for(int j=0;j<n;j++){
            if(board[row][j] == 'Q') return false;
        }

        // vertical check
        for(int i=0;i<n;i++){
            if(board[i][col] == 'Q') return false;
        }

        // left diagonal check
        for(int i=row,j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }

        // right diagonal check
        for(int i=row,j=col; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
    // Time Complexity :- O(!n) because n has n choices , later it decreases choices from top to bottom 
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j,n)){
            board[row][j] = 'Q';
            nQueens(board,row+1,n,ans);
            board[row][j] = '.';
        }
    }
}

int main(){
    // int n;
    // cout<<"Enter Array : ";
    // cin >> n;
    
    // ------------------print n numbers
    // printNum(n); 

    // -----------------factorial of n number
    // cout << factorial(n) << endl;

    // ------------------Sum of n nums
    // cout << sumOfNum(n) << endl;

    
    // ------------------fibonicci number of nth term 
    // cout << fibonicci(n) << endl;

    // ------------------check if array is sorted or not
    // vector<int> nums = {3,4,6,8};
    // int n = nums.size();
    // cout << isSorted(nums,n)<<endl;

    // --------------print all subsets
    // vector<int> nums = {1,2,3};
    // vector<int> ans;
    // printAllSubsets(nums,ans,0);

    // ------------------permutations in array
    // vector<int> nums = {1,2,3};
    // vector<vector<int>> ans;
    // getpermutations(nums,0,ans);
    
    // for(auto val : ans){
    //     for(int v : val){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    
    // ------------------permuations in string 
    string str = "abc";
    vector<string> ans;
    getpermutationsString(str,0,ans);
    
    for(string st : ans){
        for(char ch : st){
            cout << ch << " ";
        }
        cout << endl;
    }
    //-------------n Queens
    // int n = 4;
    // vector<vector<string>> ans;
    // vector<string> board(n,string(n,'.'));
    // nQueens(board,0,n,ans);
    // for(auto val : ans){
    //     for(auto v : val){
    //         cout << v << " " ;
    //     }
    //     cout << endl;
    // }

    return 0;
}