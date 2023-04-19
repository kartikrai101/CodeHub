#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data; Node* left; Node* right;
    Node(int val){
        this -> data = val; this -> left = NULL; this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root -> data < data){
        root -> right = insertIntoBST(root->right, data);
    }else{
        root -> left = insertIntoBST(root -> left, data);
    }

    return root;
}

void getData(Node* &root){
    cout << "Enter data to construct a BST" << endl;
    int data; cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return;
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    // LNR
    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

void inorder(Node* root, vector<int> &store;){
    if(root == NULL){
        return;
    }

    // LNR
    inorderTraversal(root -> left);
    store.push_back(root -> data);
    inorderTraversal(root -> right);
}

Node* flatten(Node* root){
    // flatten the given BST into a linked list like structure 
    vector<int> store;
    inorder(root, store);
    int n = store.size();

    // traverse the vector and make the flat tree
    Node* head = new Node(store[0]);
    Node* curr = head;

    for(int i=1; i< n; i++){
        Node* temp = new Node(store[i]);
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }

    //manage the head pointer and the last pointer
    curr -> left = NULL; curr -> right = NULL;
    return head;
}

int main(){
    Node* root = NULL;
    getData(root);

    inorderTraversal(root);

    return 0;
}