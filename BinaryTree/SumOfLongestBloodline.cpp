#include<bits/stdc++.h>
using namespace std;

// creating tree node structure
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
    cin >> data;

    root = new node(data);

    // base case
    if(root->data == -1){
        return NULL;
    }

    cout << "Enter the data for node left to " << data << endl;
    root -> left = buildTree(root->left);

    cout << "Enter the data for node right to " << data << endl;
    root -> right = buildTree(root->right);

    return root; //understand that when the function call is returning 
    // at the end it will return to the top root node in the last recursive return
    // which is why we are returning the root node at the end.
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
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

// every node can have two different data, <sum, length> and as soon as the length
// becomes greater than the previous max length, we will make it the max length

int sumOfLongestBloodline(node* root, int count, int maxCount){
    // base case
    if(root == NULL){
        return 
    }
}

int main(){
    node* root = NULL;

    root = buildTree(root);

    levelOrderTraversal(root);


}