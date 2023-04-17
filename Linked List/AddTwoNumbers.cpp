// You need to add two numbers that are repreented by linked lists

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int v){
        this -> data =v;
        this -> next =NULL;
    }
};

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);

    tail->next = newNode;

    tail = newNode;
}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;

        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

Node* addTwoNumbersInLists(Node* head1, Node* head2){

    // reverse both the lists
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* newList = new Node(-1); // making a list with a current Node as -1
    Node* newHead = newList;
    Node* newTail = newList;

    int carryValue = 0;
    // now add the lists until one of the pointer reaches NULL
    while(temp1 != NULL && temp2 != NULL){
        int sum = temp1->data + temp2 -> data + carryValue;
        int digitToInsert = sum %10;

        insertAtTail(newTail, digitToInsert);

        carryValue = sum/10;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while(temp1 != NULL){
        int sum = (carryValue + temp1->data);
        int digitToInsert = sum%10;

        insertAtTail(newTail, digitToInsert);

        carryValue = sum/10;
        temp1 = temp1->next;
    }

    while(temp2 != NULL){
        int sum = (carryValue + temp2->data);
        int digitToInsert = sum%10;

        insertAtTail(newTail, digitToInsert);

        carryValue = sum/10;
        temp2 = temp2->next;
    }

    while(carryValue != 0){
        insertAtTail(newTail, carryValue);
        carryValue = carryValue/10;
    }

    return reverse(newHead -> next);
}

int main(){

    Node* newNode1 = new Node(5);
    Node* newNode2 = new Node(6);

    Node* head1 = newNode1;
    Node* tail1 = newNode1;

    Node* head2 = newNode2;
    Node* tail2 = newNode2;

    insertAtTail(tail1, 0);
    insertAtTail(tail1, 0);
    insertAtTail(tail2, 9);
    insertAtTail(tail2, 9);

    print(head1);
    print(head2);

    Node* newListHead = addTwoNumbersInLists(head1, head2);
    print(newListHead);

    return 0;
}