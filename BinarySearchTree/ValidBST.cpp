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

node* createBT(node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if(data == -1){ // base case
        return NULL;
    }

    root = new node(data);

    cout << "Enter the data for left of " << data << endl;
    root -> left = createBT(root -> left);

    cout << "Enter the data for right of " << data << endl;
    root -> right = createBT(root -> right);

    return root;
}

bool validBST(node* root, int upper, int lower){
    // range for the first node = (MIN_INT, MAX_INT)

    // base case
    if(root == NULL)
        return true;

    bool ansLeft = 0, ansRight = 0;

    if(root -> data < upper && root -> data > lower){
        ansLeft = validBST(root -> left, root -> data, lower);
        ansRight = validBST(root -> right, upper, root -> data);
    }

    if(ansLeft && ansRight){
        return true;
    }

    return false;
}

// another algorithm for finding if a BST is valid or not in O(n)

bool isValidBST(node* root){
    // base case
    if(root == NULL){
        return true;
    }

    bool leftTree = isValidBST(root-> left);
    bool rightTree = isValidBST(root -> right);

    int val = root -> data;
    if(leftTree && rightTree){
        if(root -> left != NULL && root -> right != NULL){
            if(val > root -> left -> data && val < root -> right -> data)
                return true;
            else
                return false;
        }else if(root -> left != NULL && root -> right == NULL){
            if(val > root -> left -> data)
                return true;
            else
                return false;
        }else if(root -> left == NULL && root -> right != NULL){
            if(val < root -> right -> data)
                return true;
            else    
                return false;
        }
        else if(root -> left == NULL && root -> right == NULL)
            return true;
    }
    return false;
}

int main(){
    node* root = NULL;

    cout << "Enter data to construct a BST: " << endl;

    takeInput(root);
    
    levelOrderTraversal(root);

    int upperRange = INT_MAX;
    int lowerRange = INT_MIN;

    if(isValidBST(root)){
        cout << "The given tree is a BST!" << endl;
    }else{
        cout << "The given tree is not a BST!" << endl;
    }

    return 0;
}