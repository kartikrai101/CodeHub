#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int val){
        this -> data = val; this -> left = NULL; this -> right=NULL;
    }
};

Node* buildTree(Node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }
    root = new Node(data);

    cout << "Enter data to insert in left of: " << root -> data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data to insert in right of: " << root -> data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
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

void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    ans.push_back(root -> data);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
                ans.push_back(q.front() -> data);
            }else{
                return;
            }
        }else{
            if(root ->left != NULL){
                q.push(root -> left);
            }
            if(root -> right != NULL){
                q.push(root -> right);
            }
        }
    }

    return;
}

vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    return 0;
}