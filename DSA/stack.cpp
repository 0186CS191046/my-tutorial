#include<iostream>
#include<vector>
#include<list>
using namespace std;

// Stack Implementation using arrays/vector

class Stack {
    vector<int> v;
    public : 
        void push(int val){
            v.push_back(val);
        }

        void pop(){
            v.pop_back();
        }

        int top() {
            return v[v.size()-1];
        }

        bool empty(){
            return v.size() == 0;
        }
};

// Stack Implementation using Linked List
 
class Stack2 {
    list<int> ll;
    public: 
        void push(int val) {
            ll.push_front(val);
        }
        void pop(){
            ll.pop_front();
        }
        int top(){
            return ll.front();
        }
        bool empty(){
            return ll.size()==0;
        }
};

int main() {
    // Stack Implementation using arrays/vector
    // Stack s;
    // s.push(6);
    // s.push(7);
    // s.push(8);

    // while(!s.empty() ) {
    //     cout << s.top() << " " ;
    //     s.pop();
    // }
    // cout <<  endl;

    // Stack Implementation using arrays/vector
    Stack2 s2;
    s2.push(2);
    s2.push(3);

    while(!s2.empty()){
        cout << s2.top() << " " ;
        s2.pop();
    }
    cout << endl;
    return 0;
}