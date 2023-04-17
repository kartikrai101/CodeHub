#include<bits/stdc++.h>
using namespace std;

class Node {
    
    public:
        int data;
        Node* prev;
        Node* next;

    Node(int value){
        this -> data = value;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void printList(Node* &head){

}

int main(){

    Node* head = new Node(1);
    
    cout << head -> data << " " << head -> next << " " << head -> prev << endl;
    return 0;
}