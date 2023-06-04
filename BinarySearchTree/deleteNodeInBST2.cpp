#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left; Node* right;
    Node(int val){
        this -> data = val;
        this -> left = this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        // means this is the first node, so create a new node and return the node
        Node* newNode = new Node(data);
        return newNode;
    }

    if(data < root -> data){
        root -> left = insertIntoBST(root->left, data);
    }else{
        root -> right = insertIntoBST(root->right, data);
    }

    return root;
}

// convert a BST into a sorted DLL
void convertToDLL(Node* root, Node* &head){
    if(root == NULL){
        return;
    }

    convertToDLL(root -> right, head);

    root -> right = head;
    if(head != NULL){
        head -> left = root;
    }
    head = root;

    convertToDLL(root -> left, head);

}

void getData(Node* &root){
    cout << "Enter data: " << endl;
    int data; cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }

    return;
}

void inorderTraversal(Node* root){
    // LNR // NLR // LRN
    if(root == NULL){
        return;
    }

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }else{
            cout << frontNode -> data << " ";
            if(frontNode -> left)
                q.push(frontNode -> left);
            if(frontNode -> right)
                q.push(frontNode -> right);
        }
    }

    return;
}

// int replaceLeft(Node* root){
//     // bilkul left mein ja aur uski value ko target se replace kr de
// }

// delete the node and return the root pointer
Node* deleteNodeInBST(Node* root, int target){
    //base case
    if(root == NULL){
        return NULL;
    }

    if(root -> data == target){
        // case 1: no child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        // case 2: only one child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> right != NULL && root -> left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // case 3: both children
        if(root -> left != NULL && root -> right != NULL){
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteNodeInBST(root -> right, mini);

            return root;

        }
    }
    else if(root -> data > target){
        root -> left = deleteNodeInBST(root -> left, target);
        return root;
    }
    else{
        root -> right = deleteNodeInBST(root -> right, target);
        return root;
    }
}

int main(){
    Node* root=NULL;
    getData(root);

    inorderTraversal(root);
    cout << endl;
    //levelOrderTraversal(root);

    return 0;
}