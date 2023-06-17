#include<bits/stdc++.h>
using namespace std;

int solveRecursion(vector<int> &arr, int n){
    if(n==0){
        return arr[0];
    }
    if(n < 0){
        return 0;
    }

    int include = arr[n] + solveRecursion(arr, n-2);
    int exclude = solveRecursion(arr, n-1);

    return max(include, exclude);
}

// using Recursion+Memoisation
int solveMemoisation(vector<int> &arr, int n, vector<int> &dp){
    if(n == 0){
        return arr[0];
    }
    if(n < 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int include = arr[n] + solveMemoisation(arr, n-2, dp);
    int exclude = 0 + solveMemoisation(arr, n-1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}

// using tablulation
int solveTabulation(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, 0);

    dp[0] = arr[0];  // this can be derived by looking at the base case of memoization

    for(int i=1; i<n; i++){
        int include = arr[i] + dp[i-2];
        int exclude = dp[i-1];

        dp[i] = max(include, exclude);
    }

    return dp[n-1];
}

// space optimization
int spaceOptimized(vector<int> &arr){
    int n = arr.size();
    
    int prePrev = 0;
    int prev = 0;
    int curr = arr[0];

    for(int i=1; i<n; i++){
        // include and exclude cases
        int include = arr[i] + prePrev;
        int exclude = prev;

        prePrev = prev;
        prev = curr;
        curr = max(include, exclude);
    }

    return curr;
}

int maxSumOfNonAdjacent(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, -1);

    // int ans = solveRecursion(arr, n-1); - Recursive Approach
    // int ans = solveMemoisation(arr, n-1, dp); - Top-Down approach
    int ans = solveTabulation(arr);

    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "The maximum sum is: " << maxSumOfNonAdjacent(arr) << endl;

    return 0;
}