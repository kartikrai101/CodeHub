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

// data  = {1 2 4 8 -1 -1 5 -1 -1 21 -1 -1 98 12 -1 -1 55 -1 -1}

int heightOfTree(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int maxHeight = 0;

    if(root == NULL){ // means that the tree does not exist, so height = 0
        return 0;
    }

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // matlab ek level khatam ho gya
            maxHeight++;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(temp->left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }
    }

    return maxHeight;
}



int main(){
    node* root = NULL;

    root = buildTree(root);

    levelOrderTraversal(root);

    cout << "The height of given Tree is: " << heightOfTree(root);

    return 0;
}