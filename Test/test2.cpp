#include<bits/stdc++.h>
#include<map>
using namespace std;

int maximizeEqualNumbers(int n, int k, vector<int> a){
    // x E [-k, k]
    // a -> a + x
    int count = 0;
    sort(a.begin(), a.end());
    // < <min, max> > 
    vector<pair<int, int> > rangeMap;

    for(int i=0; i< n; i++){
        int num = a[i];
        int maxi = num + k;
        int mini = num - k;
        pair<int, int> p = make_pair(mini, maxi);
        cout << p.first << " " << p.second << endl;
        rangeMap.push_back(p);
    }
    int ans = 0;
    int prevMax = 0;
    for(int i=0; i< n; i++){
        if(i==0){
            count++;
            prevMax = rangeMap[i].second;
        }else{
            if(rangeMap[i].first <= prevMax){
                count++;
            }else{
                count = 1;
                prevMax = rangeMap[i].second;
            }
        }
        ans = max(ans, count);
    }

    return ans;
}

int main(){
    int n = 4;
    int k = 0;
    vector<int> arr;
    for(int i=0; i< n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    cout << maximizeEqualNumbers(n, k, arr) << endl;
    return 0;
}   