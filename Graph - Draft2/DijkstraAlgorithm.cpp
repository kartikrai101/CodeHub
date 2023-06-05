#include<bits/stdc++.h>
using namespace std;

#define map unordered_map<int, list<parir<int, int>>>
#define p pair<int, int>
#define MAX INT_MAX
#define MIN INT_MIN

vector<int> dijkstra(vector<vector<int> > &vec, int vertices, int edges, int source){
    // create the adjacency list first
    map adj;

    for(int i=0; i<edges; i++){
        int u = vec[i][0];int v = vec[i][1];int w = vec[i][2];
        p p1 = make_pair(v, w);
        p p2 = make_pair(u, w);

        adj[u].push_back(p1);
        adj[v].push_back(p2);
    }

    vector<int> dist(vertices);
    // initialize all the distance values to be INT_MAX
    for(int i=0; i< vertices; i++){
        dist[i] = MAX;
    }
    //create a set of type <distance, node>
    set<p> st;
    dist[source] = 0;
    st.insert(make_pair(0, src));

    while(!st.empty()){
        p top = *(st.begin());
        int distance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        // traverse all the neighbours of the topNode
        for(auto i: adj[topNode]){
            if(distance + i.second < dist[i.first]){
                p record = st.find(make_pair(dist[i.first], i.first));
                //if record found, erase it
                if(record != st.end()){
                    st.erase(record);
                }

                //update distance in the dist array
                dist[i.first] = distance + i.second;
                //push this record in the set
                st.insert(make_pair(dist[i.first], i.first));
            }
        }
    }

    return dist;

}

int main(){
    int a = 10;
    cout << a << endl;

    return 0;
}