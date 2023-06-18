#include<bits/stdc++.h>
using namespace std;

int solveRecursion(vector<int> &weight, vector<int> &value, int index, int maxWeight){
    // base case
    if(index == 0){
        if(weight[index] <= maxWeight){
            return weight[index];
        }else{
            return 0;
        }
    }

    // include wala case
    int include = 0;
    if(weight[index] <= maxWeight){
        include = value[index] + solveRecursion(weight, value, index-1, maxWeight-weight[index]);
    }

    //int exclude = 0;
    int exclude = solveRecursion(weight, value, index-1, maxWeight);

    int ans = max(include, exclude);
    return ans;
}

int solveMemoisation(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int> > &dp){
    if(n==0){
        if(weight[0] <= maxWeight){
            return value[0];
        }else{
            return 0;
        }
    }

    if(dp[n][maxWeight] != -1){
        return dp[n][maxWeight];
    }

    int include = 0;
    if(weight[n] <= maxWeight){
        include = value[n] + solveMemoisation(weight, value, n-1, maxWeight-weight[n], dp);
    }

    int exclude = solveMemoisation(weight, value, n-1, maxWeight, dp);

    dp[n][maxWeight] = max(include, exclude);

    return dp[n][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    //int ans = solveRecursion(weight, value, n-1, maxWeight); - using recursion

    vector<vector<int> > dp(n, vector<int> (maxWeight+1, -1));
    int ans = solveMemoisation(weight, value, n-1, maxWeight, dp);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> weight(n), value(n);

    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    for(int i=0; i<n; i++){
        cin >> value[i];
    }

    int maxWeight;
    cin >> maxWeight;

    int ans = knapsack(weight, value, n, maxWeight);

    cout << "The maximum profit is: " << ans << endl;

    return 0;
}