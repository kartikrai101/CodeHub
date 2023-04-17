#include<bits/stdc++.h>
using namespace std;

 vector<int> dfs(int node, vector<char>nodeVal, vector<vector<int> > &adj, vector<int> &vis, vector<int> &parent){
    if(node==0){
        vector<int> ans(26,0);
        return ans;
    }
    vis[node] = 1;
    vector<int> freq(26,0);
    for(int i=0; i<adj[node].size(); i++){
        int it = adj[node][i];
        if(vis[it] == 0){
            vector<int> currFreq = dfs(it, nodeVal, adj, vis, parent);
            for(int i=0; i<26; i++){
                freq[i] += currFreq[i];
            }
        }
    }
    freq[nodeVal[node-1]-'a']++;
    parent[node] = freq[nodeVal[node-1]-'a'];
    return freq;
}

vector<int> Parent_node(int N, vector<char> nodeVal, vector<vector<int> > edge){
    vector<int> ans(N);

    vector<vector<int> > adj(N+1,vector<int>());
    for(int i=0; i<edge.size(); i++){
        adj[edge[i][0]].push_back(edge[i][1]);
    }
    for(int i=0; i<adj.size(); i++){
        if(adj.size()==0) adj[i].push_back(0);
    }
    vector<int> parent(N+1);
    vector<int> vis(N+1);
    vector<int> freq = dfs(1, nodeVal, adj, vis, parent);
    for(int i=0; i<N; i++){
        ans[i] = parent[i+1];
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    for(int t_i=0; t_i<T; t_i++){
    int n;
    cin>>n;
    vector<char> nodeVal(n);
    for(int i_nodeVal = 0; i_nodeVal<n; i_nodeVal++){
        cin>>nodeVal[i_nodeVal];
    }
    vector<vector<int> > edge(n-1, vector<int>(2));
    for(int i_edge = 0; i_edge<n-1; i_edge++){
        for(int j_edge = 0; j_edge<2; j_edge++){
            cin>>edge[i_edge][j_edge];
        }
    }

    vector<int> out_;
    out_ = Parent_node(n, nodeVal, edge);
    cout<< out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++){
        cout<<" "<<out_[i_out_];
    }
    cout<<endl;
    }
    return 0;
}