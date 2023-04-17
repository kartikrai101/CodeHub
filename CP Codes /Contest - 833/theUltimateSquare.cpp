#include<bits/stdc++.h>
using namespace std;

void findRes(int numOfBlocks){
    int ans;
    if(numOfBlocks %2 == 0){
        ans = numOfBlocks/2;
    }
    else{
        ans = numOfBlocks/2 + 1;
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        findRes(n);
    }
}