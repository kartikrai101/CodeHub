#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int> > adj){
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(node);
    parent[node] = -1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //traverse all the neighbours of the topNode
        for(auto i: adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }else{
                if(i != parent[frontNode]){
                    return true;
                }
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int> > &edges, int n, int m){
    // agar kisi ka neighbour is already visited but is not the parent of that node
    // then there is a cycle in the graph
    unordered_map<int, bool> visited;
    unordered_map<int, list<int> > adj;
    for(int i=0; i< m; i++){
        int u = edges[i][0]; int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = detectCycle(i, visited, adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }

    return "No";
}

int main(){

}