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
    cin >> data;
    root = new node(data); // creating a new node for the tree

    if(root -> data == -1){
        return NULL;
    }

    cout << "Enter the data for node left to: " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data for node right to: " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
    
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // matlab k ek level traverse ho chuka hai
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

int height(node* root){
    // base case
    if(root == NULL){
        return 0;
    }

    int heightLeft = height(root -> left);
    cout << "Height Left from " << root -> data << " = " << heightLeft << endl;
    int heightRight = height(root -> right);
    cout << "Height Right from: " << root -> data << " = " << heightRight << endl;

    int ans  = max(heightLeft, heightRight) + 1;
    cout << "Height root node " << root -> data << " : " << ans << endl;

    return ans;
}

bool isBalanced(node* root){
    
    // base case
    if(root == NULL){
        return true;
    }

    if(isBalanced(root -> left) && isBalanced(root -> right))
        return true;
    else
        return false;
}

int main(){

    node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    //height(root);

    cout << isBalanced(root) << endl;

    return 0;
}

// data = { 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 }