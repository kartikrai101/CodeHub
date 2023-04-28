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

        if(front == NULL){
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

bool findPath(Node* root, vector<int> &path, int target){
    if(root == NULL){
        return false;
    }

    path.push_back(root -> data);
    if(root->data == target){
        //path.push_back(root -> data);
        return true;
    }

    bool leftTree = findPath(root -> left, path, target);
    bool rightTree = findPath(root -> right, path, target);

    if(leftTree || rightTree){
        return true;
    }

    // backtracking
    path.pop_back();
    return false;
}

Node* findLCA(Node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }

    if(root -> data == a || root -> data==b){
        return root;
    }

    //traverse the left and right subtree
    Node* leftAns = findLCA(root -> left, a, b);
    Node* rightAns = findLCA(root -> right, a, b);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }else{
        return NULL;
    }
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

    cout << endl;
    Node* lca = findLCA(root, 3, 6);
    cout << lca->data << endl;

    return 0;
}