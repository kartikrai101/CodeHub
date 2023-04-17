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

node* buildTree(node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new node(data);

    cout << "Enter the data in left of " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter the data in right of " << data << endl;
    root -> right =  buildTree(root -> right);

    return root;
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
            if(!q.empty())
                q.push(NULL);
        }else{
            cout << temp -> data << " ";
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }
    }
}

// creates the nodeToParent mapping and return a pointer to the target node
node* createParentMapping(node* root, int target, map<node*, node*> &nodeToParent){
    
    node* res = NULL; // for storing the result target node pointer 

    // level-order traversal
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL; // since the root does not have any parent, we need to make its parent pointer to NULL

    while(!q.empty()){
        
        node* front = q.front();
        q.pop();

        if(front-> data == target){
            res = front;
        }

        if( front -> left){
            nodeToParent[front->left] = front;
            q.push(front -> left);
        }
        if(front -> right){
            nodeToParent[front->right] = front;
            q.push(front -> right);
        }
    }

    return res;
}

int burnTree(node* root, map<node*, node*> &nodeToParent){

    // abhi ek visited array ka map banana padega
    // aur ek queue banani padegi to do traversal and keep current active nodes

    map<node*, bool> visited;
    queue<node*> q;

    q.push(root);  // pushing the target node in the queue first
    visited[root]  = true;
    int ans = 0;

    while(!q.empty()){

        bool flag = 0; // to mark that something has been stored in the queue
        int size = q.size(); // so that hum ek node k saarey neighbouring nodes ko process kr lein uske baak hi ans++ karein

        for(int i=0; i<size; i++){
            // process the neighbouring nodes
            node* front = q.front();
            q.pop();

            if(front -> left && !visited[front->left]){
                flag = 1;
                q.push(front-> left);
                visited[front -> left] = 1;
            }

            if(front -> right && !visited[front->right]){
                flag = 1;
                q.push(front-> right);
                visited[front -> right] = 1;
            }

            //visiting the parent neighbour of current node
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }

        }

        if(flag == 1){
            ans++;
        }
    }

    return ans;
     
}

int minTime(node* root, int target){
    // 1: create nodeToParent mapping
    // 2: search the target
    // 3: burn the tree from target

    map<node*, node*> nodeToParent;
    node* targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    cout << endl;
    cout << "The minimum time to burn the tree from 8 is: " << minTime(root, 8) << endl; 

    return 0;
}