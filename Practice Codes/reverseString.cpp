#include<bits/stdc++.h>
using namespace std;

void reverseString(string s){
    
    int count =s.length();

    int p1 =0, p2=count-1;

    while(p1 < p2){
        swap(s[p1], s[p2]);
        p1++; p2--;
    }

    cout<< s <<endl;
}

int main(){
    string str;
    cin>> str;

    reverseString(str);

    return 0;
}