#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int count = 0;
    vector<vector<int>> ans(n,vector<int>(n,0));
    int sr=0, sc=0, er=n-1, ec=n-1;
    while(sr <= er && sc <= ec){
        for(int j=sc;j<=ec;j++){
            ans[sr][j] = ++count ;
        }
        for(int i=sr+1;i<=er;i++){
            ans[i][ec] = ++count ;
        }
        for(int j=ec-1;j>=sc;j--){
            ans[er][j] = ++count ;
        }
        for(int i=er-1;i>sr;i--){
            ans[i][sc] = ++count ;
        }
        sc++;
        ec--;
        sr++;
        er--;
    }
    for(auto vec : ans){
        for(int val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
    return ans;
}

int main(){
    int n = 1;
    vector<vector<int>> result = generateMatrix(n);
    return 0;
}