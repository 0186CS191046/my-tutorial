#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int result = 0;
    int n = heights.size();

    for(int i=0;i<n;i++){
        int height = heights[i];
        for(int j=i;j<n;j++){
            int width = j-i+1;
            height = min(heights[j],height);
            int currArea = height*width;
            result = max(currArea,result);
        }
    }
    return result;
}

int largestRectangleAreaOptimal(vector<int>& heights) {
    int result = 0;
    int n = heights.size();
    stack<int>s;
    vector<int> r(n,-1);
    vector<int> l(n,-1);

    for(int i=n-1; i>=0 ;i--){
        while(!s.empty() && heights[i]<= heights[s.top()]){
            s.pop();
        }
        s.empty() ? r[i] = n : r[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) {
        s.pop();
    }
    for(int i=0; i<n ;i++){
        while(!s.empty() && heights[i]<= heights[s.top()]){
            s.pop();
        }
        s.empty() ? l[i] = -1 : l[i] = s.top();
        s.push(i);
    }

    for(int i=0;i<n;i++){
       int currArea = heights[i]* (r[i]-l[i]-1); // width = (r-l-1)
       result = max(result,currArea);
    }
    
    return result;
}
int main (){
    vector<int>heights = {2,1,5,6,2,3};
    // largestRectangleArea(heights);

    cout << largestRectangleAreaOptimal(heights) << endl;
    return 0;
}