#include<iostream>
#include<queue>
#include<deque>  // double ended queue - It means push,pop,front,back operation will happen by front or rear side
using namespace std;

class Node {
    public : 
        int data;
        Node* next;

        Node(int val){
            data = val ;
            next = NULL ;
        }
};

class Queue {
    Node* head;
    Node* tail;

    public :
        Queue(){
            head = tail = NULL ;
        }

        void push(int val){
            Node* newNode = new Node(val);
            if(head == NULL ){
                head = tail = newNode;
            }
            else{
                tail->next = newNode ;
                tail = newNode ;
            }
        }

        void pop(){
            if(head == NULL) {
                return;
            }else{
                Node* temp = head ;
                head = head->next ;
                temp->next = NULL ;
                delete temp;
            }
        }

        int front(){
            return head->data;
        }

        bool empty(){
            return head == NULL;
        }
};

class CircularQueue {
    public:
        int arr[3];
        int cap;
        int f,r ;
        int idx ;
        CircularQueue(){
            f = 0, r = -1;
            idx = 0 ;
            cap = 3;
        }

        void push(int val){
            if(idx == cap) return;
            r = (r+1)%cap ;
            arr[r] = val;
            idx ++ ;

            cout << "push--" << f <<"-" << r <<"-" << idx << endl;
        }

        void pop(){
            if(empty()) return;
            f = (f+1)%cap ;
            idx -- ;
        }

        int front(){
            if(empty()) return -1;
            return arr[f];
        }

        bool empty(){
            return idx == 0 ;
        }

        void printArr(){
            for(int i=0;i<idx;i++){
                cout << arr[i] << " ";
            }
        }
};

int main(){

    // Scratch Implementation
    // Queue q1;
    // q1.push(1);
    // q1.push(2);
    // q1.push(3);

    // cout << q1.front() << endl;
    // q1.pop();
    // cout << q1.front() << endl;
    // q1.pop();
    // cout << q1.front() << endl;
    // cout << q1.empty() << endl;
    // q1.pop();
    // cout << q1.empty() << endl;

    // Queue STL
    // queue<int> q;
    // q.push(2);
    // q.push(3);
    // q.push(4);

    // while(!q.empty()){
    //     cout << q.front() << " " ;
    //     q.pop();
    // }

    // deque STL
    // deque<int> dq;
    // dq.push_back(2);
    // dq.push_front(3);
    // dq.push_back(4);

    // while(!dq.empty()){
    //     // cout << dq.front() << " " ;
    //     cout << dq.back() << " " ;
    //     // dq.pop_front();
    //     dq.pop_back();
    // }

    // Circular Queue Implementation
    CircularQueue cq;
    cout << "starting" << endl;
    cq.push(2);
    cout << cq.front() << endl;
    cq.push(3);
    cout << cq.front() << endl;
    cq.push(4);
    cq.printArr();
    cout << endl;

    while(!cq.empty()){
        cout << cq.front() << " ";
        cq.pop();
    }
    // cout << cq.front() << endl;
    // cq.push(4);
    // cout << cq.front() << endl;
    // cq.pop();
    // cout << cq.front() << endl;
    // cq.pop();
    // cout << cq.front() << endl;
    // cq.pop();
    // cout << cq.front() << endl;

    return 0;
}