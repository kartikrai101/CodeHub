#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int N; cin >> N;
        string S; cin >> S;
        string Q; cin >> Q;

        int out;
        out = MaxProfit(N, S, Q);
        cout << out << endl;
    }
}