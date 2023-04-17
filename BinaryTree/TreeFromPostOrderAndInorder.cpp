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

int findPosition(int arr[], int element, int n){
    for(int i= 0; i< n; i++){
        if(arr[i] == element){
            return i;
        }
    }

    return -1;
}

node* solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n){

    // base case
    if(index < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    int element = post[index--];
    node* root = new node(element);
    int position = findPosition(in, element, n);

    // recursive calls
    root -> left = solve(in, post, index, inOrderStart, position-1, n);
    root -> right = solve(in, post, index, position+1, inOrderEnd, n);

    return root;
}

node* buildTree(int in[], int post[], int N){
    int postOrderIndex = N-1;

    node* ans = solve(in, post, postOrderIndex, 0, N-1, N);
    return ans;
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
    int N = 8;
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

    node* root = buildTree(in, post, 8);

    preOrderTraversal(root);

    return 0;
}