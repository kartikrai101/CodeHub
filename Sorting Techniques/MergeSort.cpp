#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i< n; i++){
        int data;
        cin >> data;
        arr[i] = data;
    }

    MergeSort(arr, 0, n-1);

    for(int i=0; i< n; i++){
        cout << arr[i] << " ";
    }
}