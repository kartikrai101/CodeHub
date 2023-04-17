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

void insertAtTail(Node* &tail, int d){
    Node* temp = tail;
    Node* newNode = new Node(d);

    if(tail == NULL){
        tail = newNode;
        return;
    }

    tail -> next = newNode;
    tail = newNode;

    return;
}

void printList(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp-> next;
    }

    cout<< endl;
    return;
}

Node* returnMiddle(Node* &head){
    Node* temp = head;

    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }

    if(count == 1){
        return temp;
    }
    if(count == 2){
        return temp->next;
    }
    
    temp = head;

    for(int i=1; i<= count/2; i++){
        cout << temp -> data << " ";
        temp = temp->next;
    }

    cout << endl;

    if(count % 2 == 0){
        return temp;
    }
    else{
        cout << temp -> data  << endl;
    }

    return temp;
}

int main(){
    Node* newNode = new Node(10);

    Node* head = newNode;
    Node* tail = newNode;

    //printList(head);

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);

    //printList(head);

    Node* ans = returnMiddle(head);
}