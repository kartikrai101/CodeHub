// convert a given BST into a Balanced BST
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    
    node(int val){
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* insertIntoBST(node* root, int data){
    // base case
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data > root -> data){
        root -> right = insertIntoBST(root->right, data);
    }else{
        root -> left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }

    return;
}

node* inorderToBST(int s, int e, vector<int> arr){
    if(s >e){
        return NULL;
    }

    int mid = s + (e-s)/2;
    // take the mid element and make it the root
    int rootVal = arr[mid];
    Node* root = new Node(rootVal);
    root -> left = inorderToBST(s, mid-1, arr);
    root -> right = inorderToBST(mid+1, e, arr);

    return root;
}

node* BalancedBST(node* root){
    vector<int> arr;
    inorder(root, arr);

    return inorderToBST(0, arr.size()-1, arr);
}

int main(){
    node* root = NULL;
    takeInput(root);

    return 0;
}