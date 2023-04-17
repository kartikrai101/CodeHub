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

// inorder traversal = LNR

void inorderTraversal(node* root){
    // base case
    if(root == NULL){
        return;
    }

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);

}

node* findKey(node* root, int K){

    node* temp = root;

    while(temp != NULL){

        if(temp -> data == K){
            return temp;
        }

        if(temp -> data > K){
            temp = temp -> left;
        }else{
            temp = temp -> right;
        }
    }

    return NULL;
}

node* findMin(node* root){
    // base case
    if(root->left == NULL){
        return root;
    }

    root -> left = findMin(root -> left);

    return root-> left;
}

node* findMax(node* root){
    // base case
    if(root->right == NULL){
        return root;
    }

    root -> right = findMax(root -> right);

    return root->right;
}

node* preAndSucc(node* root, int K){
    
    node* key = findKey(root, K);

    cout << "The key is: " << key -> data << endl;

    node* min = findMin(key->right);
    node* max = findMax(key->left);

    cout << "Predecessor is: " << max -> data << endl;
    cout << "Successor is: " << min -> data << endl;
    
    return key;
}

int main(){
    node* root = NULL;

    cout << "Enter data to construct a BST" << endl;

    takeInput(root);

    levelOrderTraversal(root);

    inorderTraversal(root);

    cout << endl;

    node* meh = preAndSucc(root, 15);

    return 0;
}