#include<bits/stdc++.h>
using namespace std;

int solveRecursion(vector<int> &days, vector<int> &cost, int n, int index){
    // base case
    if(index >= n){
        return 0;
    }

    // 1 day pass - cost[0]
    int op1 = cost[0] + solveRecursion(days, cost, n, index+1);

    // 7 days pass - cost[1]
    int i;
    for(i=index; i<n && days[i] < days[index] + 7; i++);
    int op2 = cost[1] + solveRecursion(days, cost, n, i);

    // 30 days pass - cost[2]
    for(i=index; i<n && days[i] < days[index] + 30; i++);
    int op3 = cost[2] + solveRecursion(days, cost, n, i);

    return min(op1, min(op2, op3));
}

int solveMemoization(vector<int> &days, vector<int> &cost, int n, int index, vector<int> &dp){
    // base case
    if(index >= n){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }

    // 1 day pass - cost[0]
    int op1 = cost[0] + solveRecursion(days, cost, n, index+1);

    // 7 days pass - cost[1]
    int i;
    for(i=index; i<n && days[i] < days[index] + 7; i++);
    int op2 = cost[1] + solveRecursion(days, cost, n, i);

    // 30 days pass - cost[2]
    for(i=index; i<n && days[i] < days[index] + 30; i++);
    int op3 = cost[2] + solveRecursion(days, cost, n, i);

    dp[index] = min(op1, min(op2, op3));
    return dp[index];
}

int solveTabulation(vector<int> &days, vector<int> &cost, int n){
    // create dp 
    vector<int> dp(n+1, INT_MAX);

    dp[n] = 0;

    for(int k=n-1; k>=0; k--){

        int op1 = cost[0] + dp[k+1];

        
    }
}

int minimumCost(vector<int> &days, vector<int> &cost, int n){
    //int ans = solveRecursion(days, cost, n, 0); - using recursion

    vector<int> dp(n, -1);
    int ans = solveMemoization(days, cost, n, 0, dp);

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> days(n);
    vector<int> cost(3);

    for(int i=0; i<n; i++){
        cin >> days[i];
    }

    for(int i=0; i<3; i++){
        cin >> cost[i];
    }

    cout << "The minimum cost of tickets is: " << minimumCost(days, cost, n) << endl;

    return 0;
}