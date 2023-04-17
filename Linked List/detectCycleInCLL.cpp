#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;

    Node(int v){
        this -> data = v;
        this -> next = NULL;
    }
};

Node* insertFirst(int d){
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


// there are two approaches to detect the cycle in a singly linked list
// the first one is to use map to keep the track 
// the second is to use Floyd's Algorithm to do so

// approach-1: TC = O(n), SC = O(n)
bool detectCycle(Node* head){
    if(head == NULL){
        return false;
    }

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL || visited[temp] != true){
        if(visited[temp] == true){
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
}

// approach-2: Using Floyd's Cycle Detection Algorithm

Node* detectCycleFloyd(Node* head){ // this function will return where the 
// fast and the slow pointer meet for the very first time

    if(head == NULL){
        return false;
    }

    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && slow != NULL){

        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast){
            return slow;
        }
    }

    return NULL;
}

// find the starting point of the node
Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL:
    }
    Node* slow = head;
    Node* fast = detectCycleFloyd(head);
    int count= 0;

    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
        count++;
    }

    return slow; // this will return the starting node of the cycle in the list
}

// now you need to detatch the cycle from the list and make it straight

void removeCycle(Node* head){
    if(head == NULL){
        return;
    }

    Node* startingPoint = getStartingNode(head);
    Node* temp = startingPoint;

    while(temp->next != startingPoint){
        temp = temp->next;
    }

    temp ->next = NULL;
}

int main(){
    Node* tail = insertFirst(10);

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);

    printCLL(tail);

}