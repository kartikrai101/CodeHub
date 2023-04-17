#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans;
    vector<pair<int, int> > edges;
    
    int n = 5;
    cout << detectCycleInDirectedGraph(n, edges) << endl;
    return 0;
}