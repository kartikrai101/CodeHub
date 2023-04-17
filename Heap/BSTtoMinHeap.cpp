#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    node(int val){
        this -> data  = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// create BST from the given array
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

void levelOrderTraversal(node* root){
    // make a queue and then print according to that queue
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void bstToInorder(node* root, vector<int> &ans){
    // base case
    if(root == NULL){
        return ;
    }

    // L
    bstToInorder(root -> left, ans);
    // N
    ans.push_back(root -> data);
    // R
    bstToInorder(root -> right, ans);
}

void bstPreorderInsertion(node* root, vector<int> inorderArr, int &index){
    // base case
    if(root == NULL){
        return;
    }
    // NLR
    root -> data = inorderArr[index++];
    //cout << root -> data << " ";
    bstPreorderInsertion(root -> left, inorderArr, index);
    bstPreorderInsertion(root -> right, inorderArr, index);
}

// void preorderTraversal(node* root){
//     if(root == NULL)
//         return;
    
//     cout << root -> data << " ";
//     preorderTraversal(root -> left);
//     preorderTraversal(root -> right);
// }

node* bstToMinHeap(node* root){

    // step 1: store the inorder of BST in an array
    vector<int> inorderArr;
    bstToInorder(root, inorderArr);

    // step 2: do preorder traversal in the BST ans place the values from inorder array
    int index = 0;
    bstPreorderInsertion(root, inorderArr, index);

    return root;
}

int main(){
    cout << "Enter data to create a BST: " << endl;
    node* root = NULL;
    takeInput(root);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root);

    bstToMinHeap(root);

    //preorderTraversal(root);
    cout << "Printing MinHeap: "<< endl;
    levelOrderTraversal(root);

    return 0;

}