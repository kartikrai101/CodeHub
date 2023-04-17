#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
        int data;
        node* left;
        node* right;
    
    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// data = 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

node* buildTree(node* root){
    // we use queue to build a binary tree
    cout << "Enter the data: " << endl;

    int data;
    cin>> data;
    
    root = new node(data);
    //base case
    if(root-> data == -1){
        // means that the user is inserting a NULL node
        return NULL;
    }

    cout << "Enter the data for left node of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data for right node of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(node* root){
    // binary tree ko traverse krne k liye toh apne ko queue use krna hi padta hai
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front(); // make a temporary node pointer that points to the current node
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
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

int main(){
    node* root = NULL;

    root = buildTree(root);

    levelOrderTraversal(root);

    return 0;
}