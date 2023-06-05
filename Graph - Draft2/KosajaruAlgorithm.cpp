// kosajaru's algorithm is used to find strongly connected components in a
// given graph.
// Step-1: Create the topological sorted stack 
// Step-2: Create a transpose of given graph
// Step-3: Use the topo stack and transposed adjList to get the scc

#include<bits/stdc++.h>
using namespace std;

#define map unordered_map<int, list<int>>

void getTopoStack(int node, map adj, stack<int> &topo, unordered_map<int, bool> &visited){
    visited[node] = true;
    //travserse all the neighbours of that node
    for(auto i: adj[node]){
        if(!visited[i]){
            getTopoStack(i, adj, topo, visited);
        }
    }

    st.push(node);
}

void revDFS(int node, unordered_map<int, bool> &visited, map transpose){
    visited[node] = true;
    for(auto i: transpose[node]){
        if(!visited){
            revDFS(i, visited, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int> > &edges){
    //create the adjList of the graph
    map adj;
    for(int i=0; i< edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //create the topologically sorted stack
    stack<int> topo;
    unordered_map<int, bool> visited;
    for(int i=0; i< v; i++){
        if(!visited[i]){
            getTopoStack(i, adj, topo, visited);
        }
    }
    getTopoStack(adj, topo, visited);

    //get the transpose of graph
    map transpose;
    for(int i=0; i< v; i++){
        visited[i] = 0;
        for(auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }

    // use the above ordering to do dfs traversal and count all the scc
    int count = 0;
    while(!topo.empty()){
        int top = topo.top();
        topo.pop();

        if(!visited[top]){
            count++;
            revDFS(top, visited, transpose);
        }
    }

    return count;
}

int main(){

}