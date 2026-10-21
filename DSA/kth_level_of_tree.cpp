#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std ;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = right = NULL ;
        }
};

static int idx = -1;
Node* buildTree(vector<int> preorder){  // O(n)
    idx++;;
    if(preorder[idx] == -1) return NULL ;
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void printTrees(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    printTrees(root->left);
    printTrees(root->right);
}

void printKthLevelNodes(Node* root, int k){
    if(root == NULL) return;
    if(k==1){
        cout << root->data << " " ;
        return;
    }
    printKthLevelNodes(root->left,k-1);
    printKthLevelNodes(root->right,k-1);
}

int transformToSumTree(Node* root){
    if(root == NULL) return 0;
    int leftSum = transformToSumTree(root->left);
    int rightSum = transformToSumTree(root->right);
    root->data += leftSum + rightSum;
    return root->data ;
}

// Morris InOrder Traversal :- It uses concept of inorder predecessor , we can say IP
// inorder predecessor :- rightmost node in the left subtree

vector<int> morrisInorderTravesal(Node* root){
    vector<int> ans;
    Node* curr = root;
    Node* IP = NULL;
    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            IP = curr->left;
            while(IP->right != NULL && IP->right != curr){
                IP = IP->right;
            }
            if(IP->right == NULL){
                IP->right = curr;  // create thread
                curr = curr->left; 
            }else{
                IP->right = NULL;  // delete thread
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}


 
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    // Build a tree
    Node* root = buildTree(preorder);
    // cout << root->data << endl;
    // printTrees(root);

    // printKthLevelNodes(root,2);
    // cout << transformToSumTree(root) << endl;

    vector<int> ans = morrisInorderTravesal(root);
    for(int val : ans){
        cout << val << " ";
    }

    return 0;
}