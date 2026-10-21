#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Binary tree has max 2 childs = left child and right child
// Leaf node has no childs
// Height = levels of a tree
// Subtree = Small part of a tree

class Node {
    public :
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = right = NULL;
        }
};

//------------------------build Tree
static int idx = -1;
Node* buildTree(vector<int> preorder){  // O(n)
    // cout << "idx--" << idx << endl;
    idx++;;
    if(preorder[idx] == -1) return NULL ;
    Node* root = new Node(preorder[idx]);
    // cout << root->data << endl;
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// ----------------------Tree traversal
// ----Preorder traversal
void preOrdertraversal(Node* root){
    if(root == NULL) return ;

    cout << root->data << " " ;
    preOrdertraversal(root->left);
    preOrdertraversal(root->right);
}

// ----Inorder traversal
void inOrdertraversal(Node* root){
    if(root == NULL) return ;

    inOrdertraversal(root->left);
    cout << root->data << " " ;
    inOrdertraversal(root->right);
}

//--- PostOrders traversal
void postOrdertraversal(Node* root){
    if(root == NULL) return ;

    postOrdertraversal(root->left);
    postOrdertraversal(root->right);
    cout << root->data << " ";

}

void levelorderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        // This code is for print data in different lines
        if(curr == NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        cout << curr->data << " " ;
        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
}

// Largest BST in binary tree
class Info {
    public :
        int min, max, sz; 

        Info(int mi, int ma, int size){
            min = mi;
            max = ma;
            sz = size;
        }
};

Info helper(Node* root){
    if(root == NULL){
        return Info(INT_MAX, INT_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    cout << "+++++++++++" << (root->data > left.max && root->data < right.min) << endl;
    if(root->data > left.max && root->data < right.min){
        int currMin = min(root->data, left.min);
        int currMax = max(root->data,right.max);
        int currSize = left.sz + right.sz + 1;
        return Info(currMin,currMax,currSize);
    }
    return Info(INT_MIN, INT_MAX,max(left.sz,right.sz));
}

int maxBSTSizeInBT(Node* root) {
    Info maxSize = helper(root);
    return maxSize.sz;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    // Build a tree
    // Node* root = buildTree(preorder);
    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    // ------Preorder traversal tree
    // preOrdertraversal(root);

    // ------inorder traversal tree
    // inOrdertraversal(root);

    // ------postOrder traversal tree
    // postOrdertraversal(root);

    // ------levelorder traversal - iterative approach
    // levelorderTraversal(root);

    // ---------------Largest BST in binary tree
    // Node* root = new Node(10);
    // root->left = new Node(5);
    // root->left->left = new Node(2);
    // root->left->right = new Node(6);
    // root->right = new Node(15);
    // root->right->right = new Node(8);

    // inOrdertraversal(root);
    // cout << maxBSTSizeInBT(root) << endl;

    return 0;
}