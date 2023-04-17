#include<unordered_map>
#include<list>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int> > adj;

        void addEdge(int a, int b, bool direction){
            adj[a].push_back(b);

            if(!direction){ // means that it is undirected graph
                adj[b].push_back(a);
            }
        }

        void printAdjList(){
            // we need an iterator to iterate an unordered_map 
            unordered_map<int, list<int> > :: iterator it;
            for(it = adj.begin(); it != adj.end(); it++){
                cout << (*it).first << " -> ";

                list<int> :: iterator li;
                for(li = (it -> second).begin(); li != (it->second).end(); li++){
                    cout << *li << ", ";
                }
                cout << endl;
            }
        }
};

bool bfs(int src, unordered_map<int, list<int> > &adj, unordered_map<int, bool> &vis){
    queue<int> q;
    unordered_map<int, int> parent;
    
    q.push(src);
    parent[src] = -1;
    vis[src] = true;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        // manage the neighbours
        for(auto nbr: adj[front]){
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr]= true;
                parent[nbr] = front;
            }
            else if(vis[nbr] == true && (nbr != parent[front]))
                return true;
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int> > &edges, int n, int m){
    // create an adjacency list first
    unordered_map<int, list<int> > adj;
    for(int i=0; i< edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int, bool> vis;
        
    // take care of multiple components of the graph
    for(int i=1; i<= n; i++){
        if(!vis[i]){
            if(bfs(i, adj, vis))
                return "Yes";
        }
    }
    
    return "No";
}

int main(){
    vector<vector<int> > edges{{3, 2}, {1, 2}, {2, 3}};
    int n;
    int m;
    n=3;
    m=2;

    cout << cycleDetection(edges, n, m)<< endl;
}