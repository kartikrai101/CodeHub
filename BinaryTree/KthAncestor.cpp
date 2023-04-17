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

Node* solve(node* root, int &K, int node){
    // base case
    if(root == NULL)
        return NULL;

    if(root -> data == node){
        return root;
    }
    
    node* leftAns = solve(root -> left, K, node);
    node* rightAns = solve(root -> right, K, node);

    if(leftAns != NULL && rightAns == NULL){
        K--;
        if(K <= 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL){
        K--;
        if(K <= 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }


    return NULL;
}

int kthAncestor(node* root, int k, int node){
    node* ans = solve(root, k, node);

    if(ans == NULL || ans -> data == node)
        return -1
    else    
        return ans -> data;
}


int main(){
    node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

}