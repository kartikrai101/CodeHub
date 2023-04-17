#include<iostream>
#include<vector>
#include<algorithm>
#include<array>

using namespace std;
// code studio: Reverse the array

void reverseVector(vector<int> &arr, int m){ // implementation using vector and iterators
    int size = arr.size(); 

    vector<int> reverseArr;

    vector<int>:: iterator start, end;
    start = arr.begin()+m+1;
    end = arr.end()-1;

    while(start < end){
        swap(arr[start- (arr.begin())], arr[end - (arr.begin())]);

        start++; end--;
    }

    for(int i=0; i<size; i++){
        cout<< arr[i] <<" ";
    }
}

void reverseArray(int arr[], int m, int size){
    int start = m+1; 
    int end = size-1; // initializing two pointers that will point
    // to the first and the last element of the array

    while(start < end){
        swap(arr[start], arr[end]);

        start++; end--;
    }

    for(int i =0; i<size; i++){
        cout<<arr[i]<< " ";
    }

}

int main(){

    vector<int> v; 
    v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4); v.push_back(5); v.push_back(6);
    v.push_back(7); v.push_back(8); v.push_back(9); 

    int arr[] = {1, 2, 3, 4, 5, 6};

    reverseVector(v, 3);
    cout<< endl;
    reverseArray(arr, 3, 6);

    return 0;
}