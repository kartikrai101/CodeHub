#include<bits/stdc++.h>
using namespace std;

int findCelebrity(vector<vector<int> > &arr){
    map< pair<int, int>, int> track;

    int rows = arr.size();
    int col = rows[0].size();

    for(int i=0; i< rows; i++){
        for(int j=0; j<col; j++){
            if(i != j){

            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int> > arr;

    for(int i=0; i< n; i++){
        for(int j =0; j<n; j++){
            int num;
            cin>> num;

            arr[i][j] = num;
        }
    }
}