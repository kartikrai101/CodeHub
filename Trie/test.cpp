#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> maxHeap;
    int arr[5] = {34, 89, 21, 30, 77};

    for(int i=0; i< 5; i++){
        maxHeap.push(arr[i]);
    }

    for(int i=0; i<5; i++){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    priority_queue<int, vector<int>, greater<int> > minHeap;

    int k=3;
    while(k--){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }

    while(!minHeap.empty()){

    }

    return 0;
}