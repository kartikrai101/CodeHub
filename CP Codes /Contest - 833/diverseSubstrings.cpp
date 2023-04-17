#include<bits/stdc++.h>
using namespace std;

void printAllSubstrings(vector<string> &res, string s, int n)
{
    for (int i = 0; i < n; i++)
    {
        char temp[n - i + 1];
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = s[j];
            temp[tempindex] = '\0';
            res.push_back(temp);
        }
    }
}

bool isWorking(string str){
    int len = str.length();

    map<int, int> track;
    int length = 0;

    for(int i=0; i< len; i++){
        track[i]++;
    }

    int max =0;

    for(int i =0; i< track.size(); i++){
        if(track[i] > track.size()){
            return false;
        }
    }

    return true;
}


int solve(string str, int len){

    vector<string> result;
    printAllSubstrings(result, str, len);

    int size = result.size();
    int count = 0;

    for(int i =0; i< size; i++){
        if(isWorking(result[i])){
            count++;
        }
    }

    return count;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int len; string str;
        cin >> len;
        cin >> str;

        cout << solve(str, len) << endl;
    }

    return 0;
}