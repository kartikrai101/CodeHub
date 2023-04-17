#include<bits/stdc++.h>
using namespace std;

bool isRedundant(string &s){
    int len = s.length();

    stack<char> st;

    for(int i =0; i< len; i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch=='-' || ch=='*' || ch == '/'){
            st.push(ch);
        }else{
            // ch ya toh ')' hai ya toh lowercase letter
            if(ch == ')'){
                bool isRedundant = true;

                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }

                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }

    return false;
}

int main(){
    stack<char> st;

    string input;
    cin >> input;

    if(isRedundant(input)){
        cout << "The given expression is Redundant!" << endl;
    }else{
        cout << "The given expression is Non-Redundant!" << endl;
    }

    return 0;
}