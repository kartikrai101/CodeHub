#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// there are two ways of representing a graph
// Adjacency Matrix and Adjacency List

class graph{
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

int main(){

    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    graph g;

    for(int i=0; i< m; i++){
        int p, q;
        cin >> p >> q;
        
        g.addEdge(p, q, 0); // right now we are making undirected graph so direction = 0
    }

    g.printAdjList();

    return 0;

}