#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int value){
        this -> data = value;
        this -> next = NULL;
    }
};

void insertInCLL(Node* &tail, int d){

}

Node* insertFirstNodeInCLL(int d){
    Node* newNode = new Node(d);

    newNode -> next = newNode;
    return newNode;
}

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);

    newNode -> next = tail -> next;
    tail -> next = newNode;

    tail = newNode;  
}

void printCLL(Node* tail){
    Node* temp = tail->next;

    while(temp != tail){
        cout << temp -> data << "->";
        temp = temp -> next;
    }

    cout << temp->data << "->" << temp->next->data;

    cout << endl;
}

int main(){
    Node* tail = insertFirstNodeInCLL(10);

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);

    printCLL(tail);
}