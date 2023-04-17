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

// Sort 0s, 1s and 2s in a linked list
// Node* sortList(Node* &head){
//     Node* temp = head;

//     Node* zeroHead = new Node(-1); // creating a dummy node for 0s
//     Node* zeroTail = zeroHead;
//     Node* oneHead = new Node(-1);
//     Node* oneTail = oneHead;
//     Node* twoHead = new Node(-1);
//     Node* twoTail = twoHead;

//     while(temp != NULL){
//         int value = temp -> data;

//         if(value == 0){
//             insertAtTail(zeroTail, temp);
//         }
//         else if(value == 1){
//             insertAtTail(oneTail, temp);
//         }
//         else{
//             insertAtTail(twoTail, temp);
//         }
        
//         temp = temp ->next;
//     }

//     // the 1s list is not empty
//     if(oneHead -> next != NULL){
//         zero -> tail = oneHead -> next;
//     }else{
//         zero -> tail = twoHead -> next;
//     }

//     oneTail-> next = twoHead -> next;
//     twoTail -> next = NULL;

//     head = zeroHead -> next;

//     delete zeroHead;
//     delete oneHead;
//     delete twoHead;

//     return head;
// }

// merge two sorted linked Lists

Node* mergeSortedLists(Node* &head1, Node* &head2){
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* newNode = new Node(0);
    Node* newHead = newNode;
    Node* newTail = newNode;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> data < temp2 -> data){
            insertAtTail(newTail, temp1->data);
            temp1 = temp1->next;
        }else{
            insertAtTail(newTail, temp2->data);
            temp2 = temp2 -> next;
        }
    }

    while(temp1 != NULL){
        insertAtTail(newTail, temp1 -> data);
        temp1 = temp1 -> next;
    }

    while(temp2 != NULL){
        insertAtTail(newTail, temp2 -> data);
        temp2 = temp2 -> next;
    }

    return newHead -> next;
}


Node* mergeSortOptimized(Node* &head1, Node* &head2){
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }

    if(head1->data > head2 -> data){  // making sure that the first element in the
    // list first list is always smaller than the first element in second list
        Node* tempHead1 = head1;
        head1 = head2;
        head2 = tempHead1;
    }

    Node* curr1 = head1;
    Node* next1 = curr1->next;

    Node* curr2 = head2;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){

        if((curr2->data >= curr1->data) && (curr2->data <= next1 -> data)){
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1 = curr2;
            curr2 = next2;
        }else{
            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL){
                curr1 -> next  = curr2;
                return head1;
            }
        }
    }

    return head1;

}

int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(4);

    Node* head1 = node1;
    Node* tail1 = node1;

    Node* head2 = node2;
    Node* tail2 = node2;

    insertAtTail(tail1, 5);
    insertAtTail(tail1, 14);
    insertAtTail(tail1, 22);
    insertAtTail(tail1, 28);
    insertAtTail(tail1, 31);

    insertAtTail(tail2, 6);
    insertAtTail(tail2, 12);
    insertAtTail(tail2, 13);
    insertAtTail(tail2, 17);
    insertAtTail(tail2, 19);

    print(head1);
    print(head2);

    Node* head3 = mergeSortedLists(head1, head2);
    Node* head4 = mergeSortOptimized(head1, head2);

    print(head3);
    print(head4);
}