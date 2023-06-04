#include<bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int> > adj){
    visited[node] = true;
    dfsVisited[node] = true;

    //traverse all the neighbours of the current node
    for(auto i: adj[node]){
        if(visited[i] && dfsVisited[i]){
            return true;
        }else{
            bool ans = checkCycleDFS(i, visited, dfsVisited, adj);
            return ans;
        }
    }
    //backtracking step
    dfsVisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int> > &edges){
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first; int v = edges[i].second;
        adj[u].push_back(v);
    }

    unordered_map<int, bool> dfsVisited;

    //handle all the components of the graph
    for(int i=0; i< n; i++){
        if(!visited[i]){
            bool ans = checkCycleDFS(i, visited, dfsVisited, adj);
            return ans;
        }
    }

    return false;
}

int main(){
    
}