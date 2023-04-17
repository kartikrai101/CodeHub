#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node* next;

    Node(int value){                   // constructor
        this -> data = value;         // using the '->' operator here simply says, 'this' jis class ko point kr rha hai uska 'data' member
        this -> next = NULL;          // initializing the next pointer with NULL
    }
};

void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail->next;
}

void printList(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp-> next;
    }
}

int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);

    

    return 0;
}