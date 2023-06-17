#include<bits/stdc++.h>
using namespace std;

#define lli long long int

lli solveRecursion(lli n){
    if(n == 0 || n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    int ans = (n-1) * (solveRecursion(n-1) + solveRecursion(n-2));
    return ans;
}

lli solveMemoisation(lli n, vector<lli> &dp){
    if(n == 0 || n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = (n-1) * (solveRecursion(n-1) + solveRecursion(n-2));
    return dp[n];
}

lli solveTabulation(lli n){
    vector<lli> dp(n+1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<n; i++){
        lli first = dp[i-1];
        lli second =  dp[i-2];

        lli sum = first + second;
        lli ans = (i-1) * sum;

        dp[i] = ans;
    }

    return dp[n];
}

lli countDerangements(lli n){

    lli ans = solveRecursion(n);

    return ans;
}

int main(){
    int n;
    cin >> n;

    lli ans = countDerangements(n);

    cout << "Total Derangements are: " << ans % (10^9) + 7 << endl;

    return 0;
}