#include<bits/stdc++.h>
using namespace std;

// there could always be a possiblity of disconnected components in graphs
// so you always need to take care of that

void bfs(unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    visited[node] = 1;
    q.push(node);

    // traverse the adjacency list until the queue is empty
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        // traverse all the neighbours of the frontnode and push them into the queue
        list<int> :: iterator it = adj[frontNode].begin();
        while(it != adj[frontNode].end()){
            if(!visited[*it]){
                q.push(*it);
                visited[*it] = 1;
            }
            it++;
        }
    }
}

void prepareAdjList(unordered_map<int, list<int> > &adj, vector<pair<int, int> > edges){
    int n = edges.size();
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

vector<int> BFS(int vertex, vector<pair<int, int> > edges){
    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main(){
    int vertices;
    cin >> vertices;
    int edge;
    cin >> edge;

    //cout << "saak" << endl;

    vector<pair<int, int> > edges;
    for(int i=0; i<edge; i++){
        int a, b;
        cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        edges.push_back(p);
    }

    vector<int> ans;
    ans = BFS(vertices, edges);
    //cout << "moved out of the loop" << endl;

    int n = ans.size();
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }cout << endl;
    return 0;
}