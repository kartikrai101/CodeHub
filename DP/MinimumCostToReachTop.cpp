//you have to climb up a staicase and you can either jump 1 stair, or 2 stairs
// cost[i] = cost of ith step in the staicase
// return minimum cost of climbing to the top

#include<bits/stdc++.h>
using namespace std;

// using basic recursion
int solve(vector<int> cost, int n){
    if(n == 0){ // base case
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }

    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));

    return ans;
}

// Using top-down (recursion + memoisation) method:
int solveMem(vector<int> &cost, int n, vector<int> &dp){
    if(n == 0){
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));

    return dp[n];
}

// using the tabulation approach - (Bottom-Up approach):
int solveTab(vector<int> &cost, int n){
    // create your own vector
    vector<int> dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2; i<=n-1; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}


int minimumCost(vector<int> &cost){
    int n = cost.size();
    vector<int> dp(n+1, -1);

    return min(solve(cost, dp, n-1), solve(cost, dp, n-2));
}

int main(){
    int n;
    cin >> n;
    vector<int> cost(n);

    for(int i=0; i<n; i++){
        cin >> cost[i];
    }

    cout << "The minimum cost to react the top is: " << minimumCost(cost) << endl;

    return 0;
}