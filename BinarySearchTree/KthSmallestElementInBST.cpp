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

int kthSmallestElement(node* root, int &i, int K){

    // base case
    if(root == NULL){
        return -1;
    }

    // L
    int left = kthSmallestElement(root -> left, i, K);

    if(left != -1){
        return left;
    }

    // N
    i++;
    if(i == K){
        return root -> data;
    }

    // R
    return kthSmallestElement(root -> right, i, K);
}

int main(){
    node* root = NULL;

    cout << "Enter data to construct a BST" << endl;

    takeInput(root);

    levelOrderTraversal(root);

    inorderTraversal(root);
    cout << endl;

    cout << "The Kth smallest element is: " ;
    int i = 0;

    int sml = kthSmallestElement(root, i, 3);
    cout << sml << endl;

    return 0;
}