#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool checkIndx(string s, int minJump, int maxJump,int idx){
    if(idx == s.size()-1) return true;
    if(s[idx+minJump] == "1" || s[idx+maxJump] == "1") return false;

    if(s[idx] == "0"){
        checkIndx(s,  minJump,  maxJump,  idx+minJump);
        checkIndx(s,  minJump,  maxJump,  idx+maxJump);
    } 

}

bool canReach(string s, int minJump, int maxJump) {
    int i = 0;
    while(i<s.size()){
        checkIndx(s,minJump,i);
        
    }
    return true;
}

int main(){
    canReach( "011010",  2,  3);
    return 0;
}