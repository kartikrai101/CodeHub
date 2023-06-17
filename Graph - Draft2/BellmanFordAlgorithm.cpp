// Bellman ford algorithm is used to find the shortest distance between two given
// nodes in a graph even if the weights are negative
// As a by-product, it also detects if NEGATIVE CYCLE is present in the graph or
// not!

#include<bits/stdc++.h>
using namespace std;

#define map unordered_map<int, list<int>>
#define visArr unordered_map<int, bool> 
#define vii vector<vector<int>>

int bellmanFord(int n, int m, int src, int dest, vii &edges){
    //create the adjacency list
    map adj;
    for(int i=1; i<= n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        
    }
}

int main(){

}