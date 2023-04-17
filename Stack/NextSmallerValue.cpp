#include<bits/stdc++.h>
using namespace std;

// [4 5 3 8 6]

vector<int> nextSmallerElement(vector<int> arr, int size){  
    stack<int> st;
    st.push(-1);

    vector<int> ans(size);

    for(int i=size-1; i>= 0; i--){
        int curr = arr[i];

        while(st.top() != -1 && arr[st.top()] >= curr){
            st.pop();
        }
        
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> previousSmallerElement(vector<int> arr, int size){  
    stack<int> st;
    st.push(-1);

    vector<int> ans(size);

    for(int i=0; i<size ; i++){
        int curr = arr[i];

        while(st.top() != -1 && arr[st.top()] >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

int maxArea(vector<int> &heights){

    int n = heights.size();
    
    vector<int> next(n); // to store the next smaller element
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = previousSmallerElement(heights, n);

    int area = INT_MIN;

    for(int i =0; i< n; i++){
        int l = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l*b;

        area = max(area, newArea);
    }

    return area;

}


int main(){
    vector<int> heights;

    int size; cin>> size;

    for(int i =0; i< size; i++){
        int a;
        cin>> a;
        heights.push_back(a);
    }

    cout << maxArea(heights) << endl;

    return 0;
}