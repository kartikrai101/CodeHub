#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, list<int> > adj, vector<int> &component, unordered_map<int, bool> &visited, int node){
    component.push_back(node);
    visited[node] = 1;

    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(adj, component, visited, i);
        }
    }
}

vector<vector<int> > depthFirstSearch(int V, int E, vector<vector<int> > edges){
    // you need to return the DFS of each component separately
    unordered_map<int, list<int> > adj;
    for(int i=0; i<E; i++){
        int u = edges[i][0]; int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int> > ans;
    unordered_map<int, bool> visited;

    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adj, component, visited, i);
            ans.push_back(component);
        }
    }

    return ans;
}

int main(){
    int V, E;
    cout << "Enter total vertices and edges: " << endl;
    cin >> V >> E;

    vector<vector<int> > edges(E);
    cout << "Enter all the edges in the graph: " << endl;
    for(int i=0; i< E; i++){
        vector<int> internal(2);
        int a,b;
        cin >> a >> b;
        internal[0] = a; internal[1] = b;
        edges[i] = internal;
    }

    vector<vector<int> > ans = depthFirstSearch(V, E, edges);

    for(int i=0; i< V; i++){
        cout << ans[0][i] << " ";
    }

    return 0;
}