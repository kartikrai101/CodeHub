#include<bits/stdc++.h>
using namespace std;

string solve(string str){
    map<char, int> record;
    queue<char> q;
    string ans = "";

    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        record[ch]++;

        q.push(ch);

        while(!q.empty()){
            if(record[q.front()] > 1){
                // repeating character
                q.pop();
            }else{
                // non-repeating character mil gya
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }

    return ans;
}

int main(){
    string str;
    cin >> str;

    cout << solve(str) << endl;

    return 0;
}