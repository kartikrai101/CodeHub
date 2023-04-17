// i/p: s = "daabcbaabcbc", rem = "abc"
// o/p: "dab"

// explaination: remove the leftmost occurence of the string "rem" in the string s
// and continue this until there is no remaining such substring in the string s
// ip  = daabcbaabcbc
// op1 = dabaabcbc
// op2 = dababc
// op3 = dab --> final output 

#include <bits/stdc++.h>
using namespace std;

void removeOccurence(string s, string rem){

}

int main(){
    string s, rem;

    cin>> s >> rem;

    removeOccurence(s, rem);

    return 0;
}