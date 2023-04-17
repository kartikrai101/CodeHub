#include<bits/stdc++.h>
using namespace std;

#define MAX_LEN 1000

void replaceSpace(string str){
    int len = str.length();

    for(int i =0; i<len; i++){
        if(str[i] == ' '){
            str[i] = '@';
        }
    }

    cout<< str;
}

int main(){
    string str;
    getline( cin, str ); // taking the entire string that is entered by the user

    replaceSpace(str);

    return 0;
}