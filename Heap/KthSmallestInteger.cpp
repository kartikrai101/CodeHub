#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k){
    priority_queue<int> pq;

    // step-1:
    for(int i=0; i< k; i++){
        pq.push(arr[i]);
    }

    // step-2:
    for(int i=k; i<=r-l; i++){
        int largest = pq.top();
        if(arr[i] < largest){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main(){

    int arr[5] = {7, 10, 4, 20, 15};
    cout << kthSmallest(arr, 0, 4, 4) << endl;
    
}