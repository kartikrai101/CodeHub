#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int val){
        this -> left = NULL; this -> right = NULL;
        this -> data = val;
    }
};

Node* buildTree(Node* &root){
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    //handle the first node
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data to insert in the left of: " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data to enter in the right of:  " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    // as we know that you always require a queue to traverse a tree layer-wise
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << frontNode -> data << " ";
            if(frontNode -> left != NULL){
                q.push(frontNode -> left);
            }
            if(frontNode -> right != NULL){
                q.push(frontNode -> right);
            }
        }
    }

    return ;
}

int main(){
    Node* head = NULL;

    head = buildTree(head);
    levelOrderTraversal(head);
    // cout << head -> data << endl;
    // cout << head -> left -> data << endl;
    return 0;
}