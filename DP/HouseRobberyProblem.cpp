#include<bits/stdc++.h>
using namespace std;

long long int houseRobber(vector<int> &money){
    int n= money.size();

    if(n == 1){
        return money[0];
    }

    vector<int> first, second;
    for(int i=0; i<n; i++){
        if(i!=n-1){
            first.push_back(money[i]);
        }
        if(i!=0){
            second.push_back(money[i]);
        }
    }

    return max(solveTab(first), solveTab(second));
}

int main(){
    int n;
    cin >> n;
    vector<int> money(n);
    for(int i=0; i<n; i++){
        cin >> money[i];
    }

    return 0;
}