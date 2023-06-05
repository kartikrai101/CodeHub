// prims algorithm is used to find minimum spanning tree in the given graph
// when you convert a graph into a tree such that there are n nodes and 
// n-1 edges and no cycle exists in the graph, we call it a tree
// now there could be multiple spanning trees for a given graph, so the tree with
// minimum total cost is called minimum spanning tree!
#include<bits/stdc++.h>
using namespace std;

#define graph vector<pair<pair<int, int>, int> >
#define map unordered_map<int, list<pair<int, int>>>

#define map unordered<int, list<int>>
#define p pair<int, int> 

graph calculatePrimMST(int n, int m, graph &g){
    // create the adjacency list
    map adj;
    for(int i=0; i< m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // create our 3 required data stuctures
    vector<int> minDist(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    // initialize all the data structures
    for(int i=1; i< n+1; i++){
        minDist[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // begin the algorithm
    minDist[1] = 0;
    mst[1] = true;

    //search the key 
    for(int i=1; i<= n+1; i++){
        int mini = INT_MAX;
        int u;
        for(int v = 1; v <= n; v++){
            if(mst[v] == false && minDist[v] <mini){
                u=v;
                mini = minDist[v];
            }
        }
        mst[u] = true;
        //now traverse all the neighbours of the node that has minimum distance
        for(auto i: adj[u]){
            int v = i.first;
            int w = i.second;
            if(mst[v] == false && w < minDist[v]){
                minDist[v] = w;
                parent[v] = u;
            }
        }
    }

    // now you need to construct the tree using the parent array
    graph res;
    for(int i=2; i<=n; i++){
        res.push_back({{parent[i], i}, minDist[i]});
    }

    return res;
}

int main(){

}