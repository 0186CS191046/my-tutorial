#include<iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val){
        data = val;
        prev = next = child = NULL;
    }
};

class FlattenList {
    Node* head;
    Node* tail;

    FlattenList(){
        head = tail = NULL;
    }
};

Node* flatten(Node* head) {
    if(head == NULL) return head;
    Node* curr = head;

    while(curr != NULL){
        // If a valid child
        if(curr->child != NULL){
            // flatten the child nodes
            Node* after = curr->next;
            curr->next = flatten(temp->child)
            curr->next->prev = curr;
            curr->child = NULL; 

            // find tail
            while(curr->next != NULL){
                curr = curr->next
            }

            // attach tail with next pointer
            if(after != NULL){
                curr->next = after;
                after->prev = curr;
            }
        }
        curr = curr->next;
    }

}

int main(){
    return 0;
}