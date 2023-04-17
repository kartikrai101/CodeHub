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

void levelOrderTraversal(node* root){
    queue<node* > q;
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

node* LCAinBST(node* root, node* a, node* b){
    // base case
    if(root == NULL){
        return NULL;
    }

    if(root->data < a->data && root->data < b->data){
        // means right subtree mein jao
        return LCAinBST(root->right, a, b);
    }

    if(root->data > a->data && root->data > b->data){
        // means left subtree mein jao
        return LCAinBST(root->left, a, b);
    }

    return root; 
}

int main(){
    node* root = NULL;

    cout << "Enter data to construct a BST" << endl;

    takeInput(root);

    levelOrderTraversal(root);

    return 0;
}