#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>>& maze,vector<string> &ans,int row, int col,string combination,int n,vector<vector<bool>> &vis){
     if(row<0 || col<0 || row>=n || col>=n ||  maze[row][col] == 0 || vis[row][col] == true){
        return;
    }
    if(maze[row][col] == 0) return ans;
    if(row == n-1 && col == n-1){
        ans.push_back(combination);
        return;
    }
   
    vis[row][col] = true;
    helper(maze,ans,row-1,col,combination+"U",n,vis); // Top
    helper(maze,ans,row,col+1,combination+"R",n,vis); // Right
    helper(maze,ans,row+1,col,combination+"D",n,vis); // Down
    helper(maze,ans,row,col-1,combination+"L",n,vis);// Left

    vis[row][col] = false;
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    // code here
    vector<string> ans;
    string path = "";
    int n = maze.size();
    vector<vector<bool>> vis(n,vector<bool>(n,false));
  
    helper(maze,ans,0,0,path,n,vis);
    return ans;
}
int main(){
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> result = ratInMaze(maze);

    for(string str : result){
        cout << str << endl;
    }
    return 0;
    
}