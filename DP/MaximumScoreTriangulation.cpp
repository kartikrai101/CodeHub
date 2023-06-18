#include<bits/stdc++.h>
using namespace std;

#define vii vector<vector<int> > 

int solveRecursion(vector<int> &values, int i, int j){
    if(i+1 == j){
        return 0;
    }

    int ans = INT_MAX;
    for(int k=i+1; k<j; k++){
        ans = min(ans, values[i]*values[j]*values[k] + solveRecursion(values, i,k) + solveRecursion(values, k, j));
    }

    return ans;
}

int solveMemoization(vector<int> &values, int i, int j, vii &dp){
    if(i+1 == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT_MAX;
    for(int k = i+1; k<j; k++){
        ans = min(ans, values[i]*values[j]*values[k] + solveMemoization(values, i,k, dp) + solveMemoization(values, k, j, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveTabulation(vector<int> &values, int i, int j){
    int n = values.size();
    vector<vector<int> > dp(n, vector<int> (n, 0));

    for(int i = n-1; i>=0; i--){
        
    }
}

int minimumScore(vector<int> &values){
    int n = values.size();
    // int ans = solveRecursion(values, 0, n-1); - using recursion
    vector<vector<int> > dp(n, vector<int> (n, -1));
    int ans = solveMemoization(values, 0, n-1, dp);
    return ans;
}

int main(){
    int vertices;
    cin >> vertices;

    vector<int> values(vertices);
    for(int i=0; i<vertices; i++){
        cin >> values[i];
    }

    cout << "The minimum score is: " << minimumScore(values) << endl;

    return 0;
}