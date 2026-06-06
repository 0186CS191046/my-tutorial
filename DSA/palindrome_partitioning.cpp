#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string str){
    string rev = reverse(str.begin(),str.end());
    return rev == str;
}

vector<vector<string>> partition(string s, vector<vector<string>>&ans, vector<string>&curr) {
    if(s.size()== 0){
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<s.size();i++){
        string str = s.substr(0,i+1);
        cout << "str------" << str << "-" << s.substr(i+1) << endl; 
        if(isPalindrome(str)){
            curr.push_back(str);
            partition(s.substr(i+1),ans,curr);
            curr.pop_back();
        }
    }
    return ans;
}
int main(){
    vector<vector<string>> ans;
    vector<string> part;
    partition("aab",ans,part);
    return 0;

}

