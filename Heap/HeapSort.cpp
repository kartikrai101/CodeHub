#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
        int arr[100];
        int size;
    
    MaxHeap(){
        this -> size = 0;
        this -> arr[0] = -1;
    }
};

void heapify(int arr[], int n, int i){
    // we will process the array from right to left and will process only
    // the array from 2 to n/2 -1, because it is already a heap for the leaf nodes
    // which start from n/2 to n

    int largest = i;
    int left = i*2;
    int right = i*2 + 1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){ // this is also acting as the base case of the recursion
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}   

int main(){
    MaxHeap h;
    h.insert()
}