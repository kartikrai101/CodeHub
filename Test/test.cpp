#include<bits/stdc++.h>
using namespace std;

bool verifyPalindrome(string str){
    int size = str.length();
    if(size==1){
        return true;
    }
    int s = 0;
    int e = size-1;
    while(s<e){
        if(str[s] == str[e]){
            s++;e--;
        }else{
            return false;
        }
    }

    return true;
}

string longestPalinSubstring(string str)
{
    // find the longest palindromic substring
    int n = str.length();
    int ans = INT_MIN;
    string res;

    for (int i = 0; i < str.length(); ++i) {
        for (int j = 1; j <= str.length() - i; ++j) {
            string newStr = str.substr(i, j);

            //substrings.push_back(str.substr(i, j));
            if(verifyPalindrome(newStr)){
                if(newStr.length() > ans){
                    ans = newStr.length();
                    res = newStr;
                }
            }
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    
    if(verifyPalindrome(s))
        cout << "Palindrome!" << endl;
    else{
        cout << "Non-Palindrome" << endl;
    }

    cout << longestPalinSubstring(s) << endl;

    return 0;
}