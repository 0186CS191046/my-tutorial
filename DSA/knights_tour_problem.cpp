#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<int>>&grid, int row, int col, int expectedVal, int n ){

    if(row<0 || row>=n || col<0 || col >=n || grid[row][col] != expectedVal){
        return false;
    }

    if(expectedVal == n*n -1) {
        return true;
    };
    int ans1 = isValid(grid,row-2, col+1, expectedVal+1,n);
    int ans2 = isValid(grid,row-1, col+2, expectedVal+1,n);
    int ans3 = isValid(grid,row+1, col+2, expectedVal+1,n);
    int ans4 = isValid(grid,row+2, col+1, expectedVal+1,n);
    int ans5 = isValid(grid,row+2, col-1, expectedVal+1,n);
    int ans6 = isValid(grid,row+1, col-2, expectedVal+1,n);
    int ans7 = isValid(grid,row-1, col-2, expectedVal+1,n);
    int ans8 = isValid(grid,row-2, col-1, expectedVal+1,n);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool checkValidGrid(vector<vector<int>>& grid) {
    bool result = isValid(grid,0,0, 0,grid.size());
    cout << result << endl;
    return result;
}

int main(){
    vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6}};
    cout << "start" << endl;
    bool result = checkValidGrid(grid);
    cout << result << endl;
    cout << "end" << endl;
    
    return 0;
}