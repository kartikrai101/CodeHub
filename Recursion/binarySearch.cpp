#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int s, int e, int k){
    if(s>e){
        return false;
    }

    int mid = s + (e-s)/2;

    if(arr[mid] == k){
        return true;
    }
    else if(arr[mid] > k){
        return binarySearch(arr, s, mid-1, k);
    }
    else{
        return binarySearch(arr, mid+1, e, k);
    }
}

int main(){
    int arr[] = {2, 3, 5, 6, 12, 15};

    cout << (binarySearch(arr, 0, 5, 13) ? "Key Found!" : "Key Not Found.") <<endl;

    return 0;
}