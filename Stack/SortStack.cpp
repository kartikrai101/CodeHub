#include<bits/stdc++.h>
#include<math.h>
using namespace std;

//#define INT_MIN
//#define INT_MAX

void insertAtBottom(stack<int> &st, int element){
    //base case
    if(st.empty()){
        st.push(element);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st, element);

    st.push(num);
}

void solve(stack<int> &st, int max){
    // base case
    if(st.empty()){
        return;
    }

    int num = st.top();
    int maxi = max(num, maxi);

    solve(st, maxi);

    insertAtBottom(st, maxi);
}

int main(){
    stack<int> st;

    st.push(4); st.push(3); st.push(9); st.push(7); st.push(-1); st.push(91);

    solve(st, INT_MIN);

    for(int i=0; i<st.size(); i++){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}