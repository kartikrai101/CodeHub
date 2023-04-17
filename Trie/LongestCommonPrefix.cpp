#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26]; // array of pointers of type TrieNode for each letter
        bool isTerminal;
        int childCount;
    TrieNode(char val){
        this -> data = val;
        for(int i=0; i< 26; i++){
            this -> children[i] = NULL;
        }
        this -> isTerminal = false;
        this -> childCount=0;
    }
};

class Trie{
    public:
        TrieNode* root;
    Trie(){
        root = new TrieNode('\0'); // inserting the NULL character in the root node
    }

    void insertUtil(TrieNode* root, string word){
        // base case 
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'A';

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }else{
            // create a new node and insert it from the root
            child = new TrieNode(word[0]);
            root -> childCount += 1;
            root -> children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word){
        insertUtil(root, word);
        return;
    }

    void lcp(string str, string &ans){
        for(int i=0; i< str.length(); i++){
            char ch = str[i];

            if(root -> childCount == 1){
                ans.push_back(ch);
                // move forward
                int index = ch - 'A';
                root = root ->children[index];
            }else{
                break;
            }

            if(root -> isTerminal){
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n){
    Trie* trieStrings = new Trie();

    // insert all the strings in the trie
    for(int i=0; i<n; i++){
        trieStrings -> insert(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    trieStrings -> lcp(first, ans);

    return ans;
}

int main(){
    Trie* t = new Trie();

    vector<string> arr;
    arr.push_back("CODING"); arr.push_back("CODEZEN");
    arr.push_back("CODINGNINJA"); arr.push_back("CODERS"); 

    cout << t->search("CODERS") << endl;

    cout << longestCommonPrefix(arr, 4) << endl;


}