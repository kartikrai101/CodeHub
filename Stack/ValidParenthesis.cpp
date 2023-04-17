#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(string str){
    int len = str.size();
    int i =0;
    stack<char> st;

    if(str[i] == '}' || str[i] == ']' || str[i] == ')'){
        return false;
    }

    if(len == 0){
        return false;
    }

    while(len-- && !st.empty()){
        if(str[i] == '[' || str[i] == '{' || str[i] == '('){
            st.push(str[i]);
        }else{
            if(str[i] == ']'){
                if(st.top() != '[')
                    return false;
            }else{
                st.pop();
            }

            if(str[i] == '}'){
                if(st.top() != '{')
                    return false;
            }else{
                st.pop();
            }

            if(str[i] == ')'){
                if(st.top() != '(')
                    return false;
            }else{
                st.pop();
            }
        }
        i++;
    }

    return true;
}

int main(){
    string str;
    cin >> str;

    if(validParenthesis(str)){
        cout << "Balanced" << endl;
    }else{
        cout << "Invalid Parenthesis!" << endl;
    }

    return 0;
}