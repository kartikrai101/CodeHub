// binary search tree
#include<bits/stdc++.h>
using namespace std;
#include<map>
#include<unordered_map>

class Node{
    public:
        int data; Node* left; Node* right;
    Node(int data){
        this -> data= data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoTree(Node* &root){
    int data;
    cout << "Enter data: " << endl;
    cin >> data;

    if(data == -1){
        return NULL;
    }else{
        root = new Node(data);

        cout << "Enter the value to insert in left of " << root -> data << endl;
        root -> left = insertIntoTree(root -> left);

        cout << "Enter the value to insert in right of " << root -> data << endl;
        root -> right = insertIntoTree(root -> right);
    }

    return root;
}

void levelOrderTraversal(Node* root){
    // we need to create a queue to traverse the entire queue
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp -> data << " ";
            if(temp -> left != NULL)
                q.push(temp -> left);
            if(temp -> right != NULL)
                q.push(temp -> right);
        }
    }
}
// deletion in a Binary Search Tree

int heightOfTree(Node* root){
    // height = max(left_subtree, right_subtree) + 1;
    if(root == NULL){
        return 0;
    }
    
    int leftHeight = heightOfTree(root -> left);
    int rightHeight = heightOfTree(root -> right);

    int ans = max(leftHeight, rightHeight) + 1;

    return ans;
}

int diameterOfTree(Node* root){
    // base case
    if(root == NULL){
        return 0;
    }   

    int leftDiameter = diameterOfTree(root -> left);
    int rightDiameter = diameterOfTree(root -> right);

    int combinedDiameter = heightOfTree(root -> left) + heightOfTree(root->right)+1;

    int ans = max(leftDiameter, max(combinedDiameter, rightDiameter));

    return ans;
}

Node* lca(Node* root, Node* n1, Node* n2){
    // basic approach is to find the path to both the nodes and then find the least common ancestor
    if(root == NULL){
        return NULL;
    }

    if(root -> data == n1 -> data || root -> data == n2-> data){
        return root;
    }

    Node* left = lca(root -> left, n1, n2);
    Node* right = lca(root -> right, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }
    else if(left != NULL && right == NULL){
        return left;
    }
    else if(left == NULL && right != NULL){
        return right;
    }
    else{
        return NULL;
    }
}

void kSumPath(Node* root, int K, int &count, vector<int> path){
    if(root == NULL){
        return;
    }

    path.push_back(root -> data);

    // left section
    kSumPath(root -> left, K, count, path);
    // right section
    kSumPath(root -> right, K, count, path);

    int size = path.size();
    int sum = 0;
    for(int i=size-1; i>=0; i--){
        sum += path[i];
        if(sum == K){
            count++;
        }
    }

    path.pop_back(); // backtracking step
}

// Kth ancestor in a tree
// approach: simply, find the path up to that node and then check the nth ancestor from that path

void findPath(Node* root, int k, vector<int> path, vector<int> &ans){
    if(root == NULL){
        return;
    }

    path.push_back(root -> data);

    findPath(root-> left, k, path, ans);
    findPath(root -> right, k, path, ans);

    if(root->data == k){
        // fill the ans vector with the path and return the control
        int n = path.size();
        for(int i=0; i< n; i++){
            ans.push_back(path[i]); 
        }

        return;
    }
}

// Node* kthAncestor(Node* root, int k, int n){
//     if(root == NULL){
//         return NULL;
//     }

//     vector<int> ans;
//     vector<int> path;

//     find
// }


// int balancedTreeFast(Node* root){
//     //base case
//     if(root == NULL){
//         pair<bool, int> p = make_pair(true, 0);
//         return p;
//     }

//     pair<bool, int> left = balancedTreeFast(root -> left);
//     pair<bool, int> right = balancedTreeFast(root -> right);

//     bool diff = abs(left.second - right.second) <= 1;

//     pair<bool, int> ans;
//     ans.second = max(left.second, right.second) + 1;

//     if(leftAns && rightAns && diff){
//         ans.first = true;
//     }else{
//         ans.first = false;
//     }

//     return ans;
// }

// bool isIdentical(Node* r1, Node* r2){
//     // base cases
//     if(r1 == NULL && r2 == NULL)
//         return true;
//     if(r1 != NULL && r2 == NULL)
//         return false;
//     if(r1 == NULL && r2 != NULL)
//         return false;

//     bool left = isIdentical(r1 -> left, r2 -> left);
//     bool right = isIdentical(r1 -> right, r2 -> right);

//     if(left && right && (r1 -> data == r2 -> data)){
//         return true;
//     }else{
//         return false;
//     }
// }

// pair<bool, int> sumTree(Node* root){
//     // base case
//     if(root == NULL){
//         pair<bool, int> p = make_pair(true, 0);
//         return p;
//     }
//     if(root -> left == NULL && root -> right == NULL){
//         pair<bool, int> p = make_pair(true, 0);
//         return p;
//     }

//     pair<bool, int> left = sumTree(root -> left);
//     pair<bool, int> right = sumTree(root -> right);

//     bool leftCndn = left.first;
//     bool rightCndn = right.first;

//     int sum = left.second + right.second + root -> data;
//     bool sumCheck = root -> data == left.second+right.second;

//     pair<bool, int> ans;
//     if(leftCndn && rightCndn && sumCheck){
//         ans.first = true;
//         ans.second = sum;
//     }else{
//         ans.first = false; ans.second = sum;
//     }

//     return ans;
// }

// vector<int> zigZagTraversal(Node* root){
//     vector<int> res;
//     if(root == NULL){
//         return res;
//     }

//     bool leftToRight = true;
//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()){
//         int size = q.size();
//         vector<int> ans;

//         for(int i=0; i< size; i++){
//             Node* frontNode = q.front();
//             q.pop();

//             int index = leftToRight ? i : size - i - 1;

//             ans[index] = frontNode -> data;

//             if(frontNode ->left){
//                 q.push(frontNode -> left);
//             }
//             if(frontNode -> right){
//                 q.push(frontNode -> right);
//             }
//         }

//         leftToRight = !leftToRight;

//         for(int i=0; i<ans.size(); i++){
//             res.push_back(ans[i]);
//         }
//     }

//     return res;
// }

//vertical order traversal
// vector<int> verticalOrderTraversal(Node* root){
//     vector<int> ans;
//     if(root == NULL){
//         return ans;
//     }

//     // PVKR
//     // creating a map and a queue
//     // map< horizontal distance, map< level, vector<nodes> > > nodes;
//     // queue<pair<Node*, pair<int, int> > > q;
//     map<int, map<int, vector<int> > > nodes;
//     queue< pair< Node*, pair<int, int> > > q;

//     q.push(make_pair(root, make_pair(0, 0)));

//     while(!q.empty()){
//         pair<Node*, pair<int, int> > temp = q.front();
//         q.pop();

//         int hd = temp.second.first;
//         int lvl = temp.second.second;
//         Node* frontNode = temp.first;

//         // update the mapping
//         nodes[hd][lvl].push_back(frontNode -> data);

//         if(frontNode -> left != NULL){
//             q.push(make_pair(frontNode -> left, make_pair(hd-1, lvl+1)));
//         }
//         if(frontNode -> right != NULL){
//             q.push(make_pair(frontNode -> right, make_pair(hd+1, lvl+1)));
//         }
//     }

//     // iterate the ordered map and fill the values in ans vector/array
//     map< int, map< int, vector<int> > > :: iterator i = nodes.begin();
//     while(i != nodes.end()){
//         map<int, vector<int> >::iterator j;
//         j = i.second.begin();
//         while(j != i.second.end()){
//             vector<int>::iterator k = j.second.begin();
//             while(k != j.second.end()){
//                 ans.push_back(*k);
//                 k++;
//             }
//             j++;
//         }
//         i++;
//     }

//     // the alternative way
//     // for(auto i: nodes){
//     //     for(auto j: i.second){
//     //         for(auto k: j.second)
//     //     }
//     // }

//     return ans;
// }

// sum of longest bloodline

// void solve(Node* root, int height, int maxHeight, int sum, int maxSum){
//     // base case
//     if(root == NULL){
//         if(height > maxHeight){
//             maxHeight = height; maxSum = sum;
//         }
//         else if(height == maxHeight){
//             maxSum = max(sum, maxSum);
//         }

//         return;
//     }   

//     sum = sum + root->data;
//     solve(root -> left, height+1, maxHeight, sum, maxSum);
//     solve(root -> right, height+1, maxHeight, sum, maxSum);
// }
// int sumOfLongestBloodline(Node* root){
//     if(root == NULL || (root -> left == NULL && root -> right == NULL)){
//         return root;
//     }
//     int maxSum = INT_MIN;
//     solve(root);
//     return maxSum;
// }

// pair< int, int > = pair <maxSum_if_included, maxSum_if_not_included>
// pair<int, int> maxSum(Node* root){
//     if(root == NULL){ // base case
//         pair<int, int> p = make_pair(0, 0);
//         return p;
//     }

//     pair<int, int> left = maxSum(root -> left);
//     pair<int, int> right = maxSum(root -> right);

//     // case-1: including the current node
//     pair<int, int> res;
//     res.first = root-> data + left.second+ right.second;
//     res.second = max(left.first, left.second) + max(right.first, right.second);

//     return res;
// }

// int getMaxSum(Node* root){
//     pair<int, int> ans = maxSum(root);
//     return max(ans.first, ans.second); 
// }

Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
    // base case
    Node* res = NULL;

    // level-order traversal and mark the parent node for each node
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        if(frontNode -> data == target){
            res = frontNode;
        }
        // do mapping
        if( frontNode-> left != NULL){
            nodeToParent[frontNode-> left] = frontNode;
            q.push(frontNode-> left);
        }
        if(frontNode -> right != NULL){
            nodeToParent[frontNode-> right] = frontNode;
            q.push(frontNode-> right);
        }
    }

    return res;
}

int burnTree(Node* target, map<Node*, Node*> &nodeToParent){
    // now we need to create a map of visited nodes 
    // we also need a queue to keep the current active nodes

    queue<Node*> q;
    map<Node*, bool> visited;

    q.push(target);
    visited[target] = 1;
    int ans = 0; // initial time = 0;

    while(!q.empty()){
        bool flag = 0;
        int size = q.size();

        for(int i=0; i< size; i++){
            // process the neighbouring nodes
            Node* front = q.front();
            q.pop();

            if(front -> left && !visited[front->left]){
                flag = 1;
                q.push(front-> left);
                visited[front-> left] = 1;
            }
            if(front -> right && !visited[front->right]){
                flag = 1;
                q.push(front-> right);
                visited[front-> right] = 1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] =1;
            }
        }
        if(flag == 1){
            ans++;
        }
    }

    return ans;
}

int minTime(Node* root, int target){
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}

int main(){
    Node* root = NULL;

    root = insertIntoTree(root);

    levelOrderTraversal(root);

    vector<int> path;
    vector<int> res;
    findPath(root, 9, path, res);

    // if(res.size() == 0){
    //     cout<< "The element is not present in the tree!" << endl;
    // }else{
    //     cout << "The path of the given node in tree is:" << endl;
    //     int size = res.size();
    //     for(int i=0; i<size; i++){
    //         cout << res[i] << " ";
    //     }cout << endl;
    // }

    // cout << "The maximum sum is: " << getMaxSum(root) << endl;
    cout << "The time to burn the entire tree from 9 is: " << minTime(root, 3) << endl;

    return 0;   
}