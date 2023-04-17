#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
       Node* next;

    Node(int value){
        this -> data = value;
        this -> next = NULL;
        // (*this).data = value;
        // (*this).next = NULL;
    } 

    ~Node(){
        cout << "Removed the memory taken up by the node" <<endl;
    }
};

void printList(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp -> next;
    }
    cout <<endl;
    return;
}

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}

// remove the duplicates from a sorted linked list

void removeDuplicates(Node* &head){
    if(head == NULL){
        return;
    }

    Node* temp = head;

    while(temp != NULL){
        Node* ptr = temp -> next;

        if(temp->next != NULL && (temp->data == temp->next->data)){
            while(ptr->data == temp->data){
                ptr = ptr->next;
            }
            temp -> next = ptr;
        }
        temp = ptr;
    }
}

// Remove duplicates from an unsorted Linked List

void removeDuplicatesFromUnsorted(Node* &head){
    if(head == NULL){
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    map<int, bool> visited;

    while(curr -> next != NULL){
        
        forward = curr -> next;
        int valueToCheck = curr -> data;

        if(visited[valueToCheck] == true){   // means that this value is repeated
            prev -> next = forward;
            curr = forward;
            
        }else{
            visited[curr -> data] = true;
            prev = curr;
            curr = forward;
        }
    }

    if(visited[curr->data] == true){
        prev -> next = NULL;
    }
}

int main(){
    Node* node1 = new Node(10);
    
    Node* tail = node1;
    Node* head = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 60);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 40);

    printList(head);

    //removeDuplicates(head);

    //printList(head);

    removeDuplicatesFromUnsorted(head);
    printList(head);

    return 0;
}