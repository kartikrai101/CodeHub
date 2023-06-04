// you need to find the shortest distance of each node from the given source node
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        // adjList: <node1, list< {node2, dist b/w node1 & node2} > > 
        unordered_map<int, list<pair<int, int> > > adj; 
    
    void addEdge(int u, int v, int w){
        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }

    void printAdj(){
        unordered_map<int, list<pair<int, int> > > :: iterator it = adj.begin();
        while(it != adj.end()){
            int node = it.first;
            list<pair<int, int> > :: iterator i = it.second.begin();
            cout << node << "-> ";
            //now print all the neighbours of node and their weights
            while(i != it.second.end()){
                int v = i.first;
                int weight = i.second;
                cout << "[" << v << "," << weight << "], ";
                i++;
            }
            cout << endl;
            it++;
        }
    }

    // function to get the topological sorted stack
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo){
        visited[node] = 1;
        //traverse all the neighbours of the node and do dfs for each neighbour
        for(auto neighbour: adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour, visited, topo);
            }
        }
        // fill the stack while backtracking
        topo.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &topo){
        dist[src] = 0;
        //now use the topologically sorted stack and traverse
        while(!topo.empty()){
            int node = topo.top();
            topo.pop();

            if(dist[node] != INT_MAX){
                for(auto i: adj[node]){
                    if(dist[top] + i.second < dist[i.first])
                        dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
};

int main(){

}