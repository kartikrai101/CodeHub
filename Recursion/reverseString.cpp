// reverse the given string using recursion

#include<bits/stdc++.h>
using namespace std;

string reverseString(string str, int s, int e){
    if(s>=e){
        return str;
    }

    swap(str[s], str[e]);
    s++; e--;

    return reverseString(str, s, e);
}

int main(){
    string str;
    cin>> str;

    int len = str.length();

    cout << reverseString(str, 0, len-1) << endl;

    return 0;
}