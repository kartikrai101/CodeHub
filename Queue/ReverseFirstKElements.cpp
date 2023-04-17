#include<bits/stdc++.h>
using namespace std;

void solve(queue<int> &q, int size, int K){
    stack<int> st;

    for(int i=0; i<K; i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    int num = size-K;

    for(int i=0; i<num; i++){
        int n = q.front();
        q.push(n);
        q.pop();
    }
}

int main(){
    int size;
    cin>>size;

    queue<int> q;
    for(int i =0; i<size; i++){
        int num;
        cin>> num;
        q.push(num);
    }

    for(int i =0; i<q.size(); i++){
        cout << q.front() << " ";
        q.pop();
    }

    int k;
    cin>>k;

    solve(q, size, k);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}