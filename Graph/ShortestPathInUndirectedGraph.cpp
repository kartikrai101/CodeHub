// this algorithm is used to find topological sorting of a DAG
#include<bits/stdc++.h>
#include<unordered_map>
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
            // creating an iterator for unordered map
            unordered_map<int, list<int> > :: iterator it;
            
            for(it = adj.begin(); it!=adj.end(); it++){
                cout << (*it).first << " -> ";

                list<int> :: iterator li;
                for(li = (it->second).begin(); li != (it->second).end(); li++){
                    cout << *li << ", ";
                }
                cout << endl;
            }
        }
};

void bfs(int node, unordered_map<int, list<int> > & adj, unordered_map<int, bool> &vis, queue<int> &q){
    q.push(node);
    vis[node] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        cout << front << " ";
        
        // process all the neighbours of the current node
        list<int> :: iterator it;
        for(it = adj[front].begin(); it != adj[front].end(); it++ ){
            if(!vis[*it]){
                q.push(*it);
                vis[*it] = true;
            }
        }
    }
    cout << endl;
}

void BFSTraversal(unordered_map<int, list<int> > &adj){
    queue<int> q;
    unordered_map<int, bool> vis;

    // we need to check for all the components of the graph
    for(int i=1; i<= adj.size(); i++){
        if(!vis[i]){
            bfs(i, adj, vis, q);
        }
    }
}

vector<int> shortestPathInUndirectedGraph(unordered_map<int, list<int> > &adj, int s, int t){
    // we are doing this using BFS 
    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;

    // do bfs
    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        list<int> :: iterator it;
        for(it = (adj[front]).begin(); it!= (adj[front]).end(); it++){
            if(!vis[*it]){
                // push them in the queue if they are not visited and update parents array
                vis[*it] = true;
                parent[*it] = front;
                q.push(*it);
            }
        }
    }

    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    Graph g;
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(4, 6, 0);
    g.addEdge(3, 8, 0);
    g.addEdge(6, 7, 0);
    g.addEdge(3, 8, 0);
    g.addEdge(5, 8, 0);

    g.printAdjList();

    cout << endl;

    BFSTraversal(g.adj);

    cout << endl;

    vector<int> ans = shortestPathInUndirectedGraph(g.adj, 1, 8);
    for(int i=0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}