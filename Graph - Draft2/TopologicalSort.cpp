// topological sorting is applicable only for Directed Acyclic Graph
// we can also use it to check if the given 
#include<bits/stdc++.h>
using namespace std;

void topSort(int node, unordered_map<int, list<int> > adj, unordered_map<int, bool> visited, vector<int> &ans, stack<int> &st){
    visited[node] = true;

    // traverse all the neighbours of that node
    for(auto neighbour: adj){
        if(!visited[neighbour]){
            topSort(neighbour, adj, visited, ans, st);
        }
    }

    //backtracking
    st.push(node);
    return;
}

vector<int> topologicalSort(int N, int E, vector<vector<int> > edges){
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;
    stack<int> st;
    vector<int> ans;

    for(int i=0; i< E; i++){
        int u = edges[i][0]; int v = edges[i][1];
        adj[u].push_back(v);
    }

    for(int i=0; i< N; i++){
        if(!visited[i]){
            topSort(i, adj, visited, ans, st);
        }
    }

    

    return ans;
}

int main(){

}