#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int element){
    //base case
    if(st.empty()){
        st.push(element);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st, element); // recursive call

    st.push(num);
}

void solve(stack<int> &st, int count){
    if(count <= 0){ // base case
        return;
    }

    int element = st.top();
    st.pop();
    
    insertAtBottom(st, element);
    cout << "pushing " << element << " to the bottom" << endl; 
    cout << st.top() << endl;

    solve(st, count-1);
}  

int main(){
    stack<int> st;

    int size;
    cin >> size;

    for(int i=0; i<size; i++){
        int num;
        cin >> num;
        st.push(num);
    }

    solve(st, st.size());

    for(int i=0; i<size; i++){
        cout << st.top() << " ";
        st.pop();
    }
}