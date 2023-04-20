#include<bits/stdc++.h>
using namespace std;

int solve(string str){
    if(str[0] == '0'){
        return 0;
    }

    int n = str.length();
    int ans=1;
    int count = 0;
    for(int i=0; i<n; i++){
        if(str[i] == '?'){
            count++;
        }
    }

    if(str[0] == '?'){
        ans = pow(10, count-1) * 9;
    }else{
        ans = pow(10, count);
    }

    return ans;
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        string str;
        cin >> str;

        cout << solve(str) << endl;
    }

    return 0;
}