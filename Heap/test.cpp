#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int arr[1000];
        int size;
    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        //now it's time to bring the value to its correct position
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }
    void print(){
        for(int i=1; i< size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

//heap sort algorithm is used to sort a given heap array into a sorted array
void heapSort(int arr[], int n){
    // swap the root element with the last element and reduce the size by 1
    // then you can use heapify algorithm to bring the root element to it's right place
    int largest = arr[1];
    int last = arr[n];
}

int main(){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n=5;
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout << "The heapified array is: " << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}