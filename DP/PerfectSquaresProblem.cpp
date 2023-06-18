#include<bits/stdc++.h>
using namespace std;

int solveRecursion(int n){
    // base case
    if(n == 0){
        return 0;
    }
    int ans = n;
    for(int i=1; i*i<= n; i++){
        ans = min(ans, 1+solveRecursion(n-i+1));
    }

    return ans;
}

int main(){
    
}