#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int> > edges, int n, int m, int s, int e){
    unordered_map<int, list<int> > adj;
    for(int i=0; i< m; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    // do BFS
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while(!q.empty()){
        int frontNode = q.top();
        q.pop();

        //traverse all the neighbours of the frontNode
        for(auto i: adj[frontNode]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = frontNode;
                q.push(i);
            }
        }
    }

    // prepare the shortest path from the parent map
    vector<int> ans;
    int currNode = e;
    ans.push_back(e);
    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    
}