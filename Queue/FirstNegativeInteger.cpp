#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> solve(vector<ll> &arr, ll N, ll K){
    deque<ll> dq;
    vector<ll> ans;

    // process first window of K size
    for(int i=0; i<K; i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    // store answer of first K sized window
    if(dq.size() > 0){ // means that there are must be at least one integer in 1st window that is negative
        ans.push_back(arr[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    // what we have done above is only for the first window of K size

    // Now we need to do this for the other windows
    for(int i=K; i<N; i++){
        // removal algorithm
        if(!dq.empty() && i-dq.front() >= K){ // this would mean that there was a negative number 
            dq.pop_front(); 
        }
        
        // addition
        if(arr[i] < 0){
            dq.push_back(i);
        }

        //store answer
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }

    return ans;
}

int main(){
    int size;
    cin>> size; // size of the i/p array

    vector<ll> input;

    for(int i=0; i<size; i++){ // input array
        int a;
        cin >> a;
        input.push_back(a);
    }

    int K;
    cin>> K; // the size of the window

    vector<ll> res = solve(input, size, K);

    for(int i=0; i< res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}