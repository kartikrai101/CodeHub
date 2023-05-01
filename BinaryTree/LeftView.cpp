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

int findHeight(Node* root, int target, int level){
    if(root == NULL){
        return 0;
    }

    if(root -> data == target){
        return level;
    }

    //traverse to left and right
    int leftAns = findHeight(root -> left, target, level+1);
    int rightAns = findHeight(root -> right, target, level+1);

    level = level - 1;
    return level;
}

int findHeightNew(Node* root, int target){
    if(root == NULL){
        return 0;
    }

    //create a queue to traverse the tree from root to the destination node
    int level=0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            level++;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(front -> data == target){
                return level;
            }
            if(front -> left){
                q.push(front -> left);
            }
            if(front -> right){
                q.push(front -> right);
            }
        }
    }

    return level;
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

    //cout << root -> data << endl;
    int height = findHeightNew(lca, 4);
    cout << "The height of Node 6 from root is: " << height << endl;

    return 0;
}