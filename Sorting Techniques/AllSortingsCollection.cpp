#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

// implement all the different sorting techniques
// List of all the sorting algos:
// 1. Bubble Sort ||        T.C. ->  O(N2)      S.C. -> O(1)
// 2. Insertion Sort ||     T.C. ->  O(N2)      S.C. -> O(1)
// 3. Selection Sort ||     T.C. ->  O(N2)      S.C. -> O(1) // Remarks: This is a the best sorting way out of the 1,2,3 techniques because here if the array is presorted then the T.C. reduces to O(n+d) where d is the number of inversions
// 4. Merge Sort ||         T.C. ->  O(NlogN)      S.C. -> O(N)  // Remarks: The TC reamins same for best and avg cases too
// 5 Quick Sort ||          T.C. ->  O(NlogN)      S.C. -> O(1)  // Remarks: The TC becomes O(N2) for worst case
// 6. Heap Sort ||          T.C. ->  O()      S.C. -> O()
// 7. Tree Sort ||          T.C. ->  O()      S.C. -> O()
// 8. Counting Sort ||      T.C. ->  O()      S.C. -> O()
// 9. Bucket Sort ||        T.C. ->  O()      S.C. -> O()
// 10. Radix Sort ||        T.C. ->  O()      S.C. -> O()

void BubbleSort(vector<int> &arr, int n){
    // take all the pairs of the array and swap them is arr[j] < arr[i] where j>i
    for(int i=0; i< n-1; i++){
        for(int j=i+1; j< n; j++){
            if(arr[j] < arr[i])
                swap(arr[i], arr[j]);
        }
    }
}

void InsertionSort(vector<int> &arr, int n){
    // search for the smallest element of the array and swap it with the first element of the array and repeat the process
    int mini = INT_MAX;
    int mini_index = 0;
    for(int i=0; i<n-1; i++){
        mini = arr[i];
        for(int j=i+1; j< n; j++){
            if(arr[j] < mini){
                mini = arr[j];
                mini_index = j;
            }
        }
        swap(arr[i], arr[mini_index]);
    }
}

void SelectionSort(vector<int> &arr, int n){
    // take the first element and put it to its right place in the sorted sublist that keeps growing in the array, such that all the elements to its right are greater and all the elements to the left are smaller
    int key; int j;
    for(int i=1; i< n; i++){
        key = arr[i];
        j=i;
        while(arr[j-1] > key && j>=1){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
}

void Merge(vector<int> &arr, int s, int m, int e){
    // create a new array where you keep the sorted array
    // ek array mein s to m waaley elements store kr lo, ek mein m+1 se e tak kr lo
    // uske baad ek new array mein store kr lo inhe sort krte hue using 2-pointer

    int size1 = m-s+1;
    int size2 = e-m;
    vector<int> left(size1);
    vector<int> right(size2);

    int ptr1 = 0;
    int ptr2 = 0;
    int ptr3 = s;

    for(int i=0; i< size1; i++){
        left[i] = arr[s+i];
    }
    for(int i=0; i< size2; i++){
        right[i] = arr[m+i+1];
    }

    while(ptr1< size1 && ptr2 < size2){
        if(left[ptr1] < right[ptr2]){
            arr[ptr3++] = left[ptr1++];
        }else{
            arr[ptr3++] = right[ptr2++];
        }
    }

    while(ptr1 < size1){
        arr[ptr3++] = left[ptr1++];
    }
    while(ptr2 < size2){
        arr[ptr3++] = right[ptr2++];
    }

}

void MergeSort(vector<int> &arr, int start, int end){
    // base case 
    if(start >= end)
        return;
    
    int mid = start + (end-start)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);

    Merge(arr, start, mid, end);
}

int partition(vector<int> &arr, int low, int high){
    int left, right, pivot_item = arr[low];
    left = low;
    right = high;

    while(left < right){
        while(arr[left] <= pivot_item){
            left++;
        }
        while(arr[right] > pivot_item){
            right--;
        }
        if(left < right)
            swap(arr[left], arr[right]);
    }
    // right is the final position for the pivot element
    arr[low] = arr[right];
    arr[right] = pivot_item;

    return right;
}

void QuickSort(vector<int> &arr, int low, int high){
    // find the pivot element and place it to its correct position where all the elements to its left are smaller than pivot element and all the ones to the right are greater than the pivot element, and repeat this
    // for all the elements of the array
    int pivot;
    if(high > low){ // base case
        pivot = partition(arr, low, high);
        QuickSort(arr, low, pivot-1);
        QuickSort(arr, pivot+1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i< n; i++){
        int data;
        cin >> data;
        arr[i] = data;
    }

    QuickSort(arr, 0, n-1);

    for(int i=0; i< n; i++){
        cout << arr[i] << " ";
    }
}