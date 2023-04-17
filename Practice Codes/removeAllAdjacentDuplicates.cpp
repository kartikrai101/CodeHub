#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string str){
    int len = str.length();
    int ptr = 0;

    while(ptr < str.length()){
        if(str[ptr] == str[ptr+1]){
            str.erase(ptr, 2);
            ptr=ptr-1;
            
        }
        else{
            ptr++;
        }
    }

    return str;
} 

int main(){
    string str;
    cin>> str;

    string s = removeDuplicates(str);
    cout<< s <<endl;

    return 0;
}