#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int trap (vector<int>& height) {
    int result = 0;
    int n = height.size();

    for(int i=0;i<n;i++){
        int lmax = -1, rmax = -1 ;
        for(int j=0;j<=i;j++){
            lmax = max(lmax,height[j]);
        }
        for(int k=i+1;k<n;k++){
            rmax = max(rmax,height[k]);
        }
        int currwater = min(lmax,rmax);
        if(currwater > height[i]){
            result += currwater-height[i];
        }
    }
    return result;
}

// prefix array approach
int trap2 (vector<int>& height) {
    int result = 0;
    int n = height.size();

    vector<int> leftmax(n,0);
    vector<int> rightmax(n,0);

    leftmax[0] = height[0];
    rightmax[n-1] = height[n-1];
    for(int i=1;i<n;i++){
        leftmax[i] = max(height[i],leftmax[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rightmax[i] = max(height[i],rightmax[i+1]);
    }

    for(int i=0;i<n;i++){
        result += min(leftmax[i],rightmax[i])-height[i];
    }
    return result;
}

// two-pointers approach
int trap3 (vector<int>& height) {
    int result = 0;
    int n = height.size();
    int l = 0, r = n-1;
    int lmax = 0, rmax = 0;

    while(l<r){
        lmax = max(lmax,height[l]);
        rmax = max(rmax,height[r]);

        if(lmax < rmax) {
            result += lmax - height[l];
            l++;
        }else{
            result += rmax - height[r];
            r--;
        }
    }
    return result;
}

int main (){
    vector<int>heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    // cout << trap(heights) << endl;
    // cout << trap2(heights) << endl;
    cout << trap3(heights) << endl;
    return 0;
}