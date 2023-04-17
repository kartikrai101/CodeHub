#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node* left;
        node* right;

    node(int v){
        this -> data = v;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// a function to insert a node in a tree

node* insertnode(node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new node(data);  // creating a new node

    if(root -> data == -1){
        return NULL;
    }

    cout << "Enter the data for left node of " << data << endl;
    root -> left = insertnode(root -> left);

    cout << "Enter the data for right node of " << data << endl;
    root -> right = insertnode(root -> right);

    return root;
}

// a function to do level-order traversal in the tree

void levelOrderTraversal(node* root){
    //in order to traverse through a tree we need to make a queue data-structure
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << front -> data << " ";
            if(front -> left)
                q.push(front -> left);
            if(front -> right)
                q.push(front -> right);
        }
    }
}

pair<int, int> solve(node* root){
    // base case
    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root -> left);
    pair<int, int> right = solve(root -> right);

    pair<int, int> res;

    res.first = root -> data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int getMaxSum(node* root){
    pair<int, int> ans = solve(root);

    return max(ans.first, ans.second);
}

void preOrderTraversal(node* root){
    // NLR

    if(root == NULL) //base case
        return;

    cout << root -> data << " ";

    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

int main(){
    node* root = NULL;

    root = insertnode(root);

    preOrderTraversal(root); cout << endl;

    levelOrderTraversal(root);
    // cout << root -> left -> data << endl;
    // cout << root -> right -> data << endl;

    cout << "The max sum of adjacent nodes is: " << getMaxSum(root) << endl;

    return 0;
}