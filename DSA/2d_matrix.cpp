#include<iostream>
#include<vector>
using namespace std;

// Search an element into the matrix
bool linearSearch(int matrix[][3], int row, int col, int target){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

// return index of an element into the matrix
pair<int ,int> linearSearchIndex(int matrix[][3], int row, int col, int target){
    pair<int,int> result = {-1,-1};
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j] == target){
                result = {i,j};
                return result ;
            }
        }
    }
    return result;
}

// -------------maximum Row Sum
int maxRowSum(int matrix[][3],int rows,int col){
    int maxRSum = INT_MIN;
    for(int i=0;i<rows;i++){
        int tempSum = 0;
        for(int j =0;j<col;j++){
            tempSum += matrix[i][j];
        }
        maxRSum = max(maxRSum,tempSum);
    }
    return maxRSum;
}

// ----------------Diagonal Sum--------------
// approach-1
int diagonalSum4(int matrix[][4],int n){
    int result = 0;
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i==j){
                result += matrix[i][j];  //primary diagonal
            }else if(j == n-i-1){
                result += matrix[i][j] ;  //primary diagonal
            }
        }
    }
    return result;
}

// ----approach2
int diagonalSum4Optimal(int matrix[][4],int n){
    int result = 0;
    // primary diagonal =>  i=j
    // secondary diagonal => j=n-i-1

    for(int i=0;i<n;i++){
       result += matrix[i][i];  // primary diagonal
       if(i!=n-i-1){
        result += matrix[i][n-i-1];   // secondary diagonal
       }
    }
    return result;
}

int diagonalSum3(int matrix[][3],int n){
    int result = 0;
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i==j){
                result += matrix[i][j];  //primary diagonal
            }else if(j == n-i-1){
                result += matrix[i][j] ;  //primary diagonal
            }
        }
    }
    return result;
}

int main(){
    // int matrix[4][3];   // 2d-array , row-4, col-3 with empty array
    // int rows=4;
    // int col = 3;

    // int matrix2[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};  // Initialization for this value
    // int matrix2[4][3];
    // int rows=4;
    // int col = 3;
    // cout << matrix2[2][2] << endl;   // return in 3rd row 3rd column value 

    // input matrix
    // cout << "Enter values of matrix : " ;
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<col;j++){
    //         cin >> matrix2[i][j] ;
    //     }
    // }

    // Output matrix - print all values
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<col;j++){
    //         cout << matrix2[i][j] << " " ;
    //     }
    //     cout << endl;
    // }

    // Search an element into the matrix
    // int matrix[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};  // Initialization for this value
    // int rows=4;
    // int col = 3;

    // cout << linearSearch(matrix,rows,col,5) << endl;
    // cout << linearSearch(matrix,rows,col,20) << endl;
    
    // return index of an element into the matrix
    // pair<int,int>ans = linearSearchIndex(matrix,rows,col,8);
    // cout << ans.first << "," << ans.second << endl;
    
    // -------------maximum Row Sum
    // cout << maxRowSum(matrix,rows,col) << endl;

    // -----------diagonal sum
    // for 4x4 matrix
    // int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // int n = 4;
    // cout << diagonalSum4(matrix,n) << endl;
    // cout << diagonalSum4Optimal(matrix,n) << endl;

    // for 3x3 matrix
    // int matrix[3][3] = {{1,2,3},{5,6,7},{9,10,11}};
    // int n = 3;
    // cout << diagonalSum3(matrix,n) << endl;
   
    // --------------2D-Vectors--------------------
    // It is dynamic means it's size increase or decrease during run time
    // In 2d-vector we can increase or decrease specific column by any number of columns
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};  // 3x3 matrix
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout << mat[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}