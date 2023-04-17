#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

// 1. Bubble Sort ||        T.C. ->  O(N2)      S.C. -> O(1)
// 2. Insertion Sort ||     T.C. ->  O(N2)      S.C. -> O(1)
// 3. Selection Sort ||     T.C. ->  O(N2)      S.C. -> O(1) // Remarks: This is a the best sorting way out of the 1,2,3 techniques because here if the array is presorted then the T.C. reduces to O(n+d) where d is the number of inversions

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

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i< n; i++){
        int data;
        cin >> data;
        arr[i] = data;
    }

    SelectionSort(arr, n);

    for(int i=0; i< n; i++){
        cout << arr[i] << " ";
    }
}