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

// find the number of paths where the sum is equal to K
bool findInVector(vector<int> arr, int K){
    int size = arr.size();
    int sum =0;

    for(int i =size-1; i>=0; i--){
        sum += arr[i];
        if(sum == K)
            return true;
    }

    return false;
}

void sumK(node* root, int K, int &count){
    if(root == NULL){
        return ;
    }

    vector <int> pathSum;

    pathSum.push_back(root -> data);

    sumK(root->left, K, count);
    sumK(root -> right, K, count);


    if(findInVector(pathSum, K))
        count++;

    pathSum.pop_back();
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    int count =0;

    sumK(root, 3, count);

    cout << "The number of paths are: " << count << endl;

    // vector<int> arr;
    // arr.push_back(2); arr.push_back(4); arr.push_back(3); arr.push_back(5); 
    // cout << (findInVector(arr, 6) ? "True" : "False") << endl;
}