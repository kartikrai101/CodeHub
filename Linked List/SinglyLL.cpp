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

void insertAtHead(Node* &head, int d){ // the reason for using & here is that 
// we are taking the node pointer by reference so that we can make changes to
// the actual linked list here instead of making changes to a copy of the linked list

    Node* temp = new Node(d); // creating a new node
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail->next;
}

void insertInMiddle(Node* &head, int position, int d){
    Node* newNode = new Node(d);

    Node* temp = head;

    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    Node* temp2 = temp -> next;
    temp -> next = newNode;
    newNode->next = temp2; 
}

void deleteNode(Node* &head, int position){
    Node* temp = head;

    int count = 1;
    while(count != position-1){
        temp = temp -> next;
        count++;
    }

    temp -> next = temp -> next -> next;
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

    printList(head);
    cout << endl;

    deleteNode(head, 2);

    printList(head);

    cout << endl;
    cout << head -> next << endl;

    // printList(head);

    return 0;
}