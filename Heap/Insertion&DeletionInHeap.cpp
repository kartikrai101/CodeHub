#include<bits/stdc++.h>
using namespace std;

// we implement heap using arrays
// left child: 2*i;
// right child: 2*i + 1;
// parent: i/2 th index;

class MaxHeap{
    public:
        int arr[100];
        int size;
    
    MaxHeap(){
        this -> size = 0;
        this -> arr[0] = -1; // bacause we will construct the heap using 1-based indexing
    }

    void insert(int val){
        // add that element to the end of the array and then send it to its right
        // place
        size = size+1;
        arr[size] = val;

        int i = size;
        while(i>1){
            // compare with its parent and swap if it's greater than its parent
            int parent = i/2;

            if(arr[i] > arr[parent]){
                swap(arr[i], arr[parent]);
                i = i/2;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<= size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }

    // deletion in maxHeap
    void deleteElement(){
        //deletion means to delete the top node
        // algo: 1) swap with the last node 
        // 2) remove the last node and decrease the size
        // 3) perform the heapify function to send the head node to its correct place
    
        if(size == 0){
            cout << "Nothing to delete" << endl ;
        }
        // step: 1&2
        arr[1] = arr[size];
        size = size -1;

        // step 3:
        int i = 1;
        while(i<size){
            int leftChild = i*2;
            int rightChild = i*2 + 1;

            if(leftChild < size && arr[leftChild] > arr[i]){
                swap(arr[leftChild], arr[i]);
                i = leftChild;
            }
            else if(rightChild < size && arr[rightChild] > arr[i]){
                swap(arr[rightChild], arr[i]);
                i = rightChild;
            }
            else{
                return; // means that the root node is at its correct place now
            }
        }
    }
};

class MinHeap{
    public:
        int arr[100];
        int size;
    
    MinHeap(){
        this -> size = 0;
        this -> arr[0] = -1; // bacause we will construct the heap using 1-based indexing
    }

    void insert(int val){
        // add that element to the end of the array and then send it to its right
        // place
        size = size+1;
        arr[size] = val;

        int i = size;
        while(i>1){
            // compare with its parent and swap if it's greater than its parent
            int parent = i/2;

            if(arr[i] < arr[parent]){
                swap(arr[i], arr[parent]);
                i = i/2;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<= size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};

// heap could either be maxHeap or minHeap

int main(){
    MaxHeap h1;

    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);

    cout << "Printing the  MaxHeap: " << endl;
    h1.print();
    h1.deleteElement();
    h1.print();
    h1.deleteElement();
    h1.print();

    MinHeap h2;

    h2.insert(50);
    h2.insert(55);
    h2.insert(53);
    h2.insert(52);
    h2.insert(54);

    cout << "Printing the  MinHeap: " << endl;
    h2.print();

    return 0;
}