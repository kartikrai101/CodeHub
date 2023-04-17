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

vector<int> bottomView(node* root){
    // topView, bottomView, verticalView, ye sab k liye apne ko maping krni pagedi level wise order mein
    // number line use krna padega jab ye left to right ya right to left wala sequence follow krna hoga
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int, int> bottomNode; // map< horizontal_distance, node->data >
    queue< pair< node*, int > > q; // pair < node, horizontal_distance >

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        // do one to one mapping
        bottomNode[hd] = frontNode -> data;

        // current node k left aur right sub-tree k liye same process follow karo 
        // unhe queue mein push kr k
        if(frontNode -> left){
            q.push(make_pair(frontNode -> left, hd-1));
        }
        if(frontNode -> right){
            q.push(make_pair(frontNode -> right, hd+1));
        }
    } 

    // for(auto i: bottomNode){ // i resembles a row <int, int> 
    //     ans.push_back(i.second);
    // }

    for(auto i = bottomNode.begin(); i != bottomNode.end(); i++){
        ans.push_back(i -> second);
    }

    // let's do this using an iterator
    

    return ans;
}

int main(){
    node* root = NULL;

    root = buildTree(root);

    levelOrderTraversal(root);

    cout << endl;

    vector<int> bottomViewArray = bottomView(root);

    for(int i=0; i< bottomViewArray.size(); i++){
        cout << bottomViewArray[i] << " ";
    }cout << endl;
}

// data = {1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1}