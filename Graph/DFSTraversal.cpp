#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int> > adj;

        void addEdge(int a, int b, bool direction){
            adj[a].push_back(b);

            if(!direction)
                adj[b].push_back(a);
        }

        void printAdjList(){
            unordered_map<int, list<int> > :: iterator it;
            for(it = adj.begin(); it!= adj.end(); it++){
                cout << it -> first << " ->  ";

                list<int> :: iterator li;
                for(li = (it->second).begin(); li != (it->second).end(); li++){
                    cout << *li << ", ";
                }cout << endl;
            }
        }
};

void dfs(int node, unordered_map<int, list<int> > &adj, unordered_map<int, bool> &vis,
vector<int> &ans){
    // mark that node true and move forward
    vis[node] = true;

    // traverse the neighbours of the current node
    list<int> :: iterator it;

    for(it = (adj[node]).begin(); it != (adj[node]).end(); it++){
        if(!vis[*it]){
            // if the current neighbour is not visited, push it in ans and call dfs for that node
            ans.push_back(*it);
            dfs(*it, adj, vis, ans);
        }
    }
}

vector<int> DFSTraversal(unordered_map<int, list<int> > &adj){
    unordered_map<int, bool> vis;
    vector<int> ans;
    ans.push_back(1);
    
    for(int i=0; i< adj.size(); i++){
        if(!vis[i]){
            dfs(i, adj, vis, ans);
        }
    }

    return ans;
}

int main(){
    Graph g;
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(4, 6, 0);

    g.printAdjList();

    cout << endl << endl;

    vector<int> res = DFSTraversal(g.adj);

    for(int i=0; i< res.size(); i++){
        cout << res[i] << " ";
    }cout << endl;

    return 0;
}