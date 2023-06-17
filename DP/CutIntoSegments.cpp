#include<bits/stdc++.h>
using namespace std;

int solveMemoisation(int n, int x, int y, int z, vector<int> &dp){
    if(n == 0){
        return 0;
    }

    if(n < 0){
        return INT_MIN;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int a = 1 + solveMemoisation(n-x,x,y,z, dp);
    int b = 1 + solveMemoisation(n-y,x,y,z, dp);
    int c = 1 + solveMemoisation(n-z,x,y,z, dp);

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int findMaxSegments(int n, int x, int y, int z){
    vector<int> dp(n+1, -1);

    int ans = solveMemoisation(n, x, y, z, dp);
    return ans;
}

int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    int ans = findMaxSegments(n, x, y, z);

    cout << "The maximum number of segments are: " << ans << endl;

    return 0;
}