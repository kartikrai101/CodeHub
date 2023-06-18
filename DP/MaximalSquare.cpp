#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vii vector<vector<int> > 

int solveRecursion(int i, int j, vii mat, int &maxi){
    // base case
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }

    int right = solveRecursion(i, j+1, mat, maxi);
    int diagonal = solveRecursion(i+1, j+1, mat, maxi);
    int down = solveRecursion(i+1, j, mat, maxi);

    if(mat[i][j] == 1){
        int ans = 1 + min(right, min(down, diagonal));
        maxi = max(maxi , ans);
        return ans;
    }else{
        return 0;
    }
}

// since i and j both are changing, we need to create a 2-D dp here
int solveMemoization(int i, int j, vector<vector<int> > mat, int &maxi, vector<vector<int> > &dp){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = solveRecursion(i, j+1, mat, maxi);
    int diagonal = solveRecursion(i+1, j+1, mat, maxi);
    int down = solveRecursion(i+1, j, mat, maxi);

    if(mat[i][j] == 1){
        int ans = 1 + min(right, min(down, diagonal));
        maxi = max(maxi , ans);
        dp[i][j] = ans;
        return ans;
    }else{
        return 0;
    }
}


int maxSquare(int n, int m, vii mat){
    int maxi=0;
    // int ans = solveRecursion(0, 0, mat, maxi); - using recursion
    vector<vector<int> > dp(n, vector<int> (m, -1));
    int ans = solveMemoization(0, 0, mat, maxi, dp);    
    return ans;
}

int main(){
    int m, n; 
    cin >> n >> m;

    vector<vector<int> > mat(n, vector<int> (m));

    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> mat[i][j];
        }
    }
    int ans = maxSquare(n, m, mat);
    cout << "The maximum area is: " << ans*ans << endl;

    return 0;
}