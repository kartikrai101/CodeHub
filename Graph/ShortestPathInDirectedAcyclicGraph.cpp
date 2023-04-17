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

int main(){
    Graph g;
    
    g.addEdge()
}