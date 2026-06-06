#include<iostream>
using namespace std;

// --------------------Singly Linked List
// class Node {
//     public :
//         int data;
//         Node* next;

//         Node(int val){
//             data = val;
//             next = NULL;
//         }
// };

// class List {
//     Node* head;
//     Node* tail;
//     public : 

//     List(){
//         head = tail = NULL;
//     }

//     void push_front(int val){
//         Node* newNode = new Node(val);  // dynamic 
//             // Node node(val);  // static-> this will delete when we outside of this function , so we use upper
//         if(head == NULL){
//             head = tail = newNode;
//             return;
//         }else{
//             newNode->next = head;   //(*newNode).next
//             head = newNode;
//         }
//     }

//     void push_back(int val){
//         Node* newNode = new Node(val);  // dynamic 
//         if(head == NULL){
//             head = tail = newNode;
//             return;
//         }else{
//             tail->next = newNode ;
//             tail = newNode;
//         }
//     }

//     void pop_front(){
//         if(head == NULL){
//             return;
//         }else{
//             Node* temp = head;
//             head = temp->next ;
//             temp->next = NULL;
//             delete temp; 
//         }
//     }

//     void pop_back(){ 
//         if(head == NULL){
//             return;
//         }else{
//             Node* temp = head;
//             while(temp->next->next !=NULL){
//                 temp = temp->next;
//                 // cout << temp->data << " " ;
//             }
//             Node* delTemp = temp->next;
//             temp->next = NULL;
//             delete delTemp;
//         }
//     }

//     void insertAtPos(int val, int pos){
//         if(pos<0) return;
//         else if(pos == 0) {
//            return push_front(val);

//         }
//         Node* temp = head;
//         Node* curr = temp;
//         int count = 0;


//         Node* newNode = new Node(val);

//         while(count<pos){
//             curr = temp;
//             temp = temp->next;
//             count++;
//         }
//         Node* afterNode = temp;
//         curr->next = newNode;
//         newNode->next = afterNode;
//     }

//     int searchInList(int val){
//         int idx = 0;
//         Node* temp = head;

//         while(temp != NULL ){
//             if(temp->data == val){
//                 return idx;
//             }
//             temp = temp->next;
//             idx++;
//         }
        
//         return -1;
//     }

//     void printList(){
//         Node* temp = head;
//         while(temp != NULL){
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

//----------------------Doubly Linked List
// class Node {
//     public:
//         int data;
//         Node* next ;
//         Node* prev ;

//         Node (int val){
//             data = val; 
//             next = NULL;
//             prev = NULL;
//         }
// };

// class DLL {
//     Node* head;
//     Node* tail;
//     public :

//     DLL(){
//         head = tail = NULL;
//     }

//     void push_front(int val){
//         Node* newNode = new Node(val);
//         if(head == NULL){
//             head = tail = newNode;
//         }else{
//             newNode->next = head;
//             head->prev = newNode;
//             head = newNode;
//         }
//         cout << "head--" << head->data << endl;
//     }

//     void push_back(int val){
//         Node* newNode = new Node(val);
//         if(head == NULL){
//             head = newNode;
//         }else{
//             cout << "val---" << tail->data << endl;
//             tail->next = newNode;
//             newNode->prev = tail;
//             tail = newNode;
//         }
//     }

//     void pop_front(){
//         if(head==NULL){
//             cout << "List is Empty!"<<endl;
//         }else if(head == tail){
//             Node* temp = head;
//             delete temp;
//             head = tail = NULL;
//         }else{
//             Node* temp = head;
//             head = head->next;
//             head->prev = NULL;
//             temp->next = NULL;
//             delete temp;
//         }
//     }

//     void pop_back(){
//         if(head == NULL){
//             cout << "List is empty!" << endl;
//         }else if(head == tail){
//             Node* temp = head;
//             delete temp;
//             head = tail = NULL;
//         }
//         else{
//             Node* temp = tail;
//             tail = tail->prev;
//             if(tail != NULL){
//                 tail->next = NULL;
//             }
//             temp->prev = NULL;
//             delete temp;
//         }
//     }

//     void printDLL(){
//         Node* temp = head;
//         while(temp!= NULL){
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

//----------------------Doubly Linked List
class Node {
    public : 
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class CircularList {
    Node* head;
    Node* tail;

    public : 
        CircularList(){
            head = tail = NULL;
        }

        void insertAtHead(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
                tail->next = head;
            }
            else {
                newNode->next = head;
                head = newNode;
                tail->next = head;
            }
        }

        void insertAtTail(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
                tail->next = head;
            }else{
                newNode->next = head;
                tail->next = newNode;
                tail = newNode;
            }
        }

        void deleteAtHead(){
            if(head==NULL) return;
            else if(head==tail){
                Node* temp = head;
                head = tail = NULL;
                delete temp;
            }
            else{
                Node* temp = head;
                head= head->next;
                tail->next = head;
                temp->next = NULL;
                delete temp;
            }
        }

        void deleteAtTail(){
            if(head==NULL) return;
            else if(head==tail){
                delete tail;
                head = tail = NULL;
            }
            else{
                Node* prev = head ;
                Node* temp = tail;
                while(prev->next != tail){
                    prev = prev->next;
                }
                tail = prev;
                tail->next = head;
                temp->next = NULL;
                delete temp;
            }
        }

        void printList(){
            if(head == NULL) return;
            Node* temp = head->next;
            cout << head->data << "->" ;
            while(temp != head){
                cout << temp->data << "->" ;
                temp = temp->next;
            }
            cout << head->data << endl;
        }
};

int main(){
    //---------------------Singly Linked List
    // List l1;
    // l1.push_front(1);
    // l1.push_front(2);
    // l1.push_front(3);
    // l1.push_front(4);
    // l1.push_front(5);
    // l1.printList();

    // l1.push_back(3);
    // l1.push_back(4);
    // l1.push_back(5);
    
    // l1.printList();

    // l1.pop_front();
    // l1.pop_front();

    // l1.printList();
    // l1.pop_back();
    // l1.printList();

    // l1.insertAtPos(6,4);
    // l1.printList();

    // cout << l1.searchInList(6) << endl;

    // -------------------------------Doubly Linked List
    // DLL l2;
    // l2.push_front(1);
    // l2.push_front(2);
    // l2.push_front(3);
    // l2.printDLL();

    // l2.push_back(4);
    // l2.push_back(5);
    // l2.push_back(6);
    // l2.printDLL();

    // l2.pop_front();
    // l2.pop_front();
    // l2.printDLL();

    // l2.pop_back();
    // l2.pop_back();
    // l2.printDLL();

    //----------------------Doubly Linked List
    CircularList l3;
    l3.insertAtHead(1);
    // l3.insertAtHead(2);
    // l3.insertAtHead(3);
    l3.printList();

    // l3.insertAtTail(4);
    l3.insertAtTail(5);
    l3.insertAtTail(6);
    l3.printList();

    // l3.deleteAtHead();
    // l3.deleteAtHead();
    // l3.printList();

    l3.deleteAtTail();
    l3.deleteAtTail();
    l3.printList();


    return 0;
}

