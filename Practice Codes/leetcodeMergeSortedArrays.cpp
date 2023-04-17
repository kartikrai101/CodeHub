#include<bits/stdc++.h>
using namespace std;

// merge two sorted arrays into a third sorted array

void mergeSortedArrays(int arr1[], int n, int arr2[], int m, int arr3[]){

    int i=0, j=0, k=0;

    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }else{
            arr3[k++] = arr2[j++];
        }
    }

    while(i<n){
        arr3[k++] = arr1[i++];
    }

    while(j<m){
        arr3[k++] = arr2[j++];
    }

    for(int i =0; i<m+n; i++){
        cout<< arr3[i] << " ";
    }
}

int main(){
    int arr1[] = {1, 2, 3};
    int arr2[] = {2, 5, 6};

    int arr3[6] = {0};

    mergeSortedArrays(arr1, 3, arr2, 3, arr3);

    return 0;
}
