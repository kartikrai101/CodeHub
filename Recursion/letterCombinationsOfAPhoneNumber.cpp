#include<bits/stdc++.h>
using namespace std;

void solve(string digit, string output, int index, vector<string> & ans, string reference[]){

    // base case
    if(index >= digit.length()){
        ans.push_back(output);
        return;
    }

    int currDigit = digit[index] - '0';
    string value = reference[currDigit];

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(digit, output, index+1, ans, reference);
        output.pop_back();
    }
}

int main(){
    string digit;
    cin>>digit;

    string reference[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int index=0;
    string output = "";
    vector<string> ans;

    solve(digit, output, index, ans, reference);

    for(int i=0; i< ans.size(); i++){
        cout << ans[i] <<endl;
    }
    return 0;
}