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

void inorderTraversal(node* root){
    if(root == NULL)
        return;
    
    // LNR
    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

void inorderToStore(node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }

    inorderToStore(root -> left, arr);
    arr.push_back(root -> data);
    inorderToStore(root -> right, arr);
}

// now we have two sorted arrays

vector<int> mergeSort(vector<int> &arr1, vector<int> &arr2){
    // we have two sorted arrays and we need to merge them

    int ptr1 =0, ptr2 =0;
    vector<int> ans;

    while(ptr1 < arr1.size() && ptr2 < arr2.size()){
        if(arr1[ptr1] < arr2[ptr2]){
            ans.push_back(arr1[ptr1]);
            ptr1++;
        }else{
            ans.push_back(arr2[ptr2]);
            ptr2++;
        }
    }

    while(ptr1 < arr1.size()){
        ans.push_back(arr1[ptr1++]);
    }

    while(ptr2 < arr2.size()){
        ans.push_back(arr2[ptr2++]);
    }

    return ans;
}

node* inorderToBST(vector<int> &arr, int s, int e){

    // base case
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;

    node* root = new node(arr[mid]);

    root -> left = inorderToBST(arr, s, mid-1);
    root -> right = inorderToBST(arr, mid+1, e);

    return root;
}

int main(){
    node* root1 = NULL;
    node* root2 = NULL;

    vector<int> arr1;
    vector<int> arr2;

    takeInput(root1);
    takeInput(root2);

    cout << "BST1: " << endl;
    inorderTraversal(root1);
    cout << endl;
    cout << "BST2: " << endl;
    inorderTraversal(root2);

    inorderToStore(root1, arr1);
    inorderToStore(root2, arr2);

    vector<int> combinedArr = mergeSort(arr1, arr2);

    cout << endl;

    node* root3 = inorderToBST(combinedArr, 0, combinedArr.size()-1);

    cout << "BST3: " << endl;
    inorderTraversal(root3);

    return 0;
}