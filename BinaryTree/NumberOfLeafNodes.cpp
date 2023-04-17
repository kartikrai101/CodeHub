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

node* buildTree(node* root){
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

int numberOfLeafNodes(node* root){
    queue<node*> q;
    q.push(root);
    int count = 0;

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp -> left){
            q.push(temp->left);
        }
        if(temp -> right){
            q.push(temp -> right);
        }

        if(!temp -> right && !temp -> left)
            count++;
    }

    return count;
}

int main(){
    node* root = NULL;

    root = buildTree(root);

    levelOrderTraversal(root);

    cout << "Total Number of Leaf Nodes are: " << numberOfLeafNodes(root) << endl;

    return 0;
}