// creating a graph and graph nodes
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int> > adj;
    
    void createGraph(int arr[][2], int n){
        for(int i=0; i< n; i++){
            int u = arr[i][0];
            int v = arr[i][1];
            // for a unidirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        //simply need to traverse the adjacency list
        unordered_map<int, list<int> > :: iterator it = adj.begin();
        while(it != adj.end()){
            cout << (it -> first) << "->";
            list<int> :: iterator li = it -> second.begin();
            while(li != it -> second.end()){
                cout << *li << ", ";
                li++;
            }cout<< endl;
            it++;
        }
    }
};

int main(){
    cout << "Enter the value of n: " << endl;
    int n; cin >> n;
    int arr[n][2];

    for(int i=0; i< n; i++){
        int a, b;
        cin>> a >> b;
        arr[i][0] = a; arr[i][1] = b;
    }

    Graph g;
    g.createGraph(arr, n);
    g.printGraph();

    return 0;
}

// the structure of vector<vector<int> > :
// [[u1, v1], [u1, v1],, [u1, v1],[u1, v1],[u1, v1], [u1, v1]]