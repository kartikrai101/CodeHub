#include<bits/stdc++.h>
using namespace std;

void solve(queue<int> &q){

    cout << q.front() << " " << q.back() << endl;
     
    //base case
    if(q.front() == q.back()){
        return;
    }

    int num = q.front();
    q.pop();

    solve(q);

    q.push(num);
}

queue<int> queueReversal(queue<int> q){
    if(q.size() <= 1){
        return q;
    }

    solve(q);

    return q;
}

int main(){
    queue<int> q;

    for(int i=1; i< 6; i++){
        q.push(i);
    }

    queue<int> reversed = queueReversal(q);

    while(!reversed.empty()){
        cout << reversed.front() << " ";
        reversed.pop();
    }
}