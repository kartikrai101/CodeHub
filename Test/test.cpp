#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int> > edges, int n, int m, int s, int t){
    //basically we need the adjacency list first
    unordered_map<int, list<int> > adj;
    
    for(int i=0; i<m; i++){
        int u =edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // now create the visited and the parent arrays
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    // do BFS
    queue<int> q;
    q.push(s);
    parent[s] = -1;

    //traverse the queue until it is empty
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //traverse all the neighbours of the frontNode
        for(auto i: adj[frontNode]){
            if(!visited[i]){
                visited[i] = 1;
                parent[i] = frontNode;
                q.push(i);
            }
        }
    }

    // get the shortest path using the parent map
    vector<int> ans;
    ans.push_back(t);
    int currNode = t;
    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int mai(){

}