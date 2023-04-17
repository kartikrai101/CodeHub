// perform bubble sort using recursion

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int *ptr, int n){
    if(n == 0 || n == 1){
        return;
    }

    for(int i=0; i<n-1; i++){
        if(ptr[i] > ptr[i+1]){
            swap(ptr[i], ptr[i+1]);
        }
    }

    bubbleSort(ptr, n-1);
}

int main(){
    int n;
    cin>>n;

    int *ptr = new int[n]; // creating a dynamic array in heap

    for(int i=0; i<n; i++){ // taking all the values of the array from our user
        cin>>ptr[i];
    }

    bubbleSort(ptr, n);

    for(int i=0; i<n; i++){
        cout << ptr[i] << " ";
    }
    
    delete []ptr; // deleting the memory in heap after using it

    return 0;

}