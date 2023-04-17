#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
        int arr[100];
        int size;

    MaxHeap(int size){
        this -> size = 0;
        this -> arr[0] = -1;
    }
};

// heapify algorithm for maxHeap, used to convert a given array into a heap array
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
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout << "Printing the heapified array" << endl;

    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}