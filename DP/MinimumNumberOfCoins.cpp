#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &coins, int amount, vector<int> &dp){
    if(amount == 0){
        return 0;
    }

    if(amount < 0){
        return INT_MAX;
    }

    if(dp[amount] != -1){
        return dp[amount];
    }

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans = solveMem(coins, amount - coins[i], dp);

        if(ans != INT_MAX)
            mini = min(mini, ans+1);
    }
    dp[amount] = mini;
    return dp[amount];
}

int solveTab(vector<int> &coins, int amount){
    vector<int> dp(amount+1, INT_MAX);
    // base values 
    dp[0] = 0;

    for(int i=1; i<=amount; i++){
        for(int j=0; j<coins.size(); j++){
            if(i - coins[j] > 0 && dp[i-coins[j]] != INT_MAX){
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
    }

    if(dp[amount] == INT_MAX){
        return -1;
    }
    return dp[amount];
}

int minimumCoins(vector<int> coins, int amount){
    int n = coins.size();
    vector<int> dp(amount+1, -1);

    //int ans = solveMem(coins, amount, dp);  => for solving via memoization
    int ans = solveTab(coins, amount);  // => for solving via tabulation

    return ans;
}

int main(){
    int n; 
    cin >> n;
    vector<int> coins(n);
    for(int i =0; i<n; i++){
        cin >> coins[i];
    }
    int amount;
    cin >> amount;

    if(minimumCoins(coins, amount) == -1){
        cout << "Not possible!" << endl;
    }else{
        cout << "The minimum number of coins are: " << minimumCoins(coins, amount) << endl;
    }
    
    return 0;
}