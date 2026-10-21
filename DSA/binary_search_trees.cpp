#include<iostream>
#include<vector>
using namespace std;

// Binary search tree has one rule that left child is always leass than root and right child is always greater than root.
// In inorder travesal we always get data in acsending sorted order.
// in traversal time complexity is height of the tree means O(log n) .

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = right = NULL;
        }
};

// build BST using array
Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    else if(val < root->data){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}

Node* buildTree(vector<int>&arr){
    Node* root = NULL;
    for(int i=0;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
    return root;
}

// search key in the BST
bool search(Node* root,int key){
    if(root == NULL) return false;
    if(root->data == key) return true;
    if(key < root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}

// left most child in the right subtree : inorder successor has at most 0 or 1 child.
Node* getInorderSuccessor(Node* root){
    while( root != NULL && root->left != NULL ){
        root = root->left;
    }
    return root;
}

Node* deleteNodeInBST(Node* root, int key){
    if(root == NULL) return NULL;
    if(root->data == key){
        // key == root
        if(root->left == NULL){
            Node* temp = root->right;
            delete root ;
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            delete root ;
            return temp;
        }else{
            Node* inorderSuccessor = getInorderSuccessor(root->right); 
            root->data = inorderSuccessor->data;
            root->right = deleteNodeInBST(root->right,inorderSuccessor->data);
        }
    }else if(root->data < key){
        root->right = deleteNodeInBST(root->right,key);
    }else{
        root->left = deleteNodeInBST(root->left,key);
    }
    return root;
}

// Tree Inorder traversal
void inOrderTravesal(Node* root){
    if(root == NULL) return;
    inOrderTravesal(root->left);
    cout << root->data << " ";
    inOrderTravesal(root->right);
}

// merge two BSTs

void inorder(Node* root, vector<int>&arr){
    if(root == NULL) return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

Node* merge(Node* root1, Node* root2){
    vector<int>arr1;
    vector<int>arr2;
    inorder(root1,arr1);
    inorder(root2,arr2);

    int i=0,j=0;
    vector<int>temp;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }else{
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size()){
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()){
        temp.push_back(arr2[j]);
        j++;
    }
    Node* root = buildTree(temp);
    return root;
}

// -------get inorder predecessor and successor in BST
vector<int> searchKey(Node* root, int key, int predecessor, int successor){
    if(root == NULL) {
        vector<int> ans = {predecessor,successor};
        return ans;
    };
    if(key < root->data){
        successor = root->data;
        return searchKey(root->left,key,predecessor,successor);
    }else if(key > root->data){
        predecessor = root->data;
        return searchKey(root->right,key,predecessor,successor); 
    }else{
        Node* temp = root->left;
        // cout << "+++++++++++++++" << temp->data << endl;
        // To get predecessor traverse root right most nodes of the left subtree
        while(temp != NULL){
            predecessor = temp->data;
            temp = temp->right;
        }
        
        // To get predecessor traverse root right most nodes of the left subtree
        temp = root->right;
        while(root != NULL){
            successor = temp->data;
            root = root->left;
        }
        
        return {predecessor,successor};
    }
}

vector<int> inorderPredSuccessor(Node* root, int key){
    return searchKey(root, key, INT_MIN, INT_MAX);
}

// 2nd method - get inorder predecessor and successor in BST
// To get predecessor
Node* rightMostNodeOfLeftSubtree(Node* root){
    Node* ans ;
    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}

// To get successor
Node* leftMostNodeOfRightSubtree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> inorderPredSuccessor2(Node* root, int key){
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL){
        if(key < curr->data){
            succ = curr;
            curr = curr->left;
        }else if(key > curr->data){
            pred = curr;
            curr = curr->right;
        }else{
            if(curr->left != NULL){
                pred = rightMostNodeOfLeftSubtree(curr->left);
            }
            if(curr->right != NULL){
                succ = leftMostNodeOfRightSubtree(curr->right);
            }
            break;
        }
    }
    return {pred != NULL ? pred->data : -1,succ != NULL ? succ->data : -1};
}

int main(){
//     vector<int> nums = {3,2,1,4,5};
//     Node* root = buildTree(nums);

    // inOrderTravesal(root);
    // cout << endl;
    // cout << search(root,5) << endl;

    // Node* root2 = deleteNodeInBST(root,1);
    // inOrderTravesal(root2);

    // -------------------Merge two BSTs
    // vector<int> nums1 = {3,2,1,4,5};
    // vector<int> nums2 = {6,4,7,9,0};
    // Node* root1 = buildTree(nums1);
    // Node* root2 = buildTree(nums2);

    // Node* root = merge(root1,root2);
    // inOrderTravesal(root);

    // get inorder predecessor and successor in BST
    vector<int> nums = {3,2,1,4,5,7,8,0};
    Node* root3 = buildTree(nums);
    inOrderTravesal(root3);
    vector<int> ans = inorderPredSuccessor2(root3,5);
    cout << endl;
    for(int val : ans){
        cout << val << " ";
    }
    

    return 0;
}