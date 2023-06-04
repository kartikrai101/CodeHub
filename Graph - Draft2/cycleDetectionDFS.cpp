#include<bits/stdc++.h>
using namespace std;

bool dfsCycleDetection(int node, unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited, int parent){
    // the condition is pretty clear to detect a cycle:
    // 1: The node is already visited, and
    // 2: The node is not the parent of the current node

    visited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetect = dfsCycleDetection(neighbour, adj, visited, node);
            if(cycleDetect)
                return true;
        }else{
            if(neighbour != parent)
                return true;
        }
    }
    
    return false;
}

void cycleDetection(vector<vector<int> > edges, int E, int V){
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;

    //create the adjacency list
    for(int i=0; i< E; i++){
        int u = edges[i][0]; int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //traverse the unvisited nodes for making sure that we traverse all the components of the graph
    int parent = -1;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            bool ans = dfsCycleDetection(i, adj, visited, parent);
            return ans;
        }
    }
}

int main(){

}