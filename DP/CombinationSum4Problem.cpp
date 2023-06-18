#include<bits/stdc++.h>
using namespace std;

int solveRecursion(vector<int> &nums, int target){
    if(target == 0){
        return 1;
    }

    if(target < 0){
        return 0;
    }

    int ans =0;
    // now process for all the values of the nums array
    for(int i=0; i<nums.size(); i++){
        ans += solveRecursion(nums, target-nums[i]);
    }

    return ans;
}

int solveMemoization(vector<int> &nums, int target, vector<int> &dp){
    if(target < 0)
        return 0;
    if(target == 0)
        return 1;

    if(dp[target] != -1)
        return dp[target];

    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans += solveMemoization(nums, target-nums[i], dp);
    }

    dp[target] = ans;
    return dp[target];
}

int solveTabulation(vector<int> &nums, int target){
    vector<int> dp(target+1, 0);

    dp[0] = 1;

    for(int i=1; i<=target; i++){
        for(int j=0; j<nums.size(); j++){
            if(i-nums[j] > 0)
                dp[i] += dp[i-nums[j]];
        }
    }

    return dp[target];
}


int findWays(vector<int> nums, int target){
    //int ans = solveRecursion(nums, target); - using recursion

    vector<int> dp(target+1, -1);
    int ans = solveMemoization(nums, target, dp);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int target; cin >> target;

    cout << "The number of ways are: " << findWays(nums, target) << endl;

    return 0;
}