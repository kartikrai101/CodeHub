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

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;

        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

Node* findMiddle(Node* head){
    if(head == NULL){
        return NULL;
    }

    if(head -> next == NULL){
        return head;
    }

    Node* fast = head->next;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast -> next -> next;
        slow = slow ->next;
    }

    return slow;
}

bool isPalindrome(Node* head){
    if(head -> next == NULL){
        return true;
    }

    Node* middle = findMiddle(head);

    Node* temp = middle -> next;
    middle -> next = reverseList(temp);

    Node* head1 = head; 
    Node* head2 = middle -> next;

    while(head2 != NULL){
        if( head1 -> data != head2 -> data){
            return false;
        }
        head2 = head2 -> next;
        head1 = head1 -> next;
    }

    return true;

}

int main(){
    Node* newNode = new Node(1);

    Node* head = newNode;
    Node* tail = newNode;
    
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    
    print(head);

    cout << isPalindrome(head) << endl;
}