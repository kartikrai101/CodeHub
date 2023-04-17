#include<bits/stdc++.h>
using namespace std;

string wordNumber(int n){
    if(n == 1){
        return "one";
    }
    else if(n == 2){
        return "two";
    }
        else if(n == 3){
        return "three";
    }
        else if(n == 4){
        return "four";
    }
        else if(n == 5){
        return "five";
    }
        else if(n == 6){
        return "six";
    }
        else if(n == 7){
        return "seven";
    }
        else if(n == 8){
        return "eight";
    }
        else if(n == 9){
        return "nine";
    }
        else if(n == 0){
        return "zero";
    }

    return "not_recognised";
}

void sayDigit(int n){

    string s = to_string(n);
    string s2 = strrev(s);

    int num = stoi(s2);

    while(num>0){
        string word = wordNumber(num%10);
        num = num/10;

        cout << word << " ";
    }
}

int main(){
    int n;
    cin>>n;

    sayDigit(n);

    return 0;
}