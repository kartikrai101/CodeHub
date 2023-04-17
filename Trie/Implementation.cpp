#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
    TrieNode(char val){
        this -> data = val;
        for(int i=0; i< 26; i++){
            this -> children[i] = NULL;
        }
        this -> isTerminal = false;
    }
};

class Trie{
    public:
        TrieNode* root;

    Trie(){ // always perform all the initialization operations inside the constructor of a class
        root = new TrieNode('\0');
    }

    // INSERTING

    void insertUtil( TrieNode* root, string word ){
        // base case 
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }
        
        int index = word[0] - 'A';

        if(root->children[index]){
            insertUtil(root->children[index], word.substr(1));
        }else{
            TrieNode* child = new TrieNode(word[0]);
            root -> children[index] = child;
            insertUtil(child, word.substr(1));
        }
    }

    void insert(string word){
        insertUtil(root, word);
        return;
    }

    // SEARCHING

    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index]){
            if(word[0] == root->children[index]->data){
                child = root -> children[index];
            }else{
                return false;
            }
        }else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word){
        return searchUtil(root, word);
    }

    bool deleteUtil(TrieNode* &root, string word){
        // base case
        if(word.length() == 0){
            if(root -> isTerminal){
                root->isTerminal = false;
                return true;
            }else{
                return false;
            }
        }

        int index = word[0] - 'A';

        TrieNode* child;

        if(root->children[index]){
            if(word[0] == root->children[index]->data){
                child = root -> children[index];
            }else{
                return false;
            }
        }else{
            return false;
        }

        return deleteUtil(child, word.substr(1));
    }

    bool deleteWord(string word){
        return deleteUtil(root, word);
    }
};

int main(){
    Trie* t = new Trie();

    t->insert("KARTIK");
    t->insert("KART");
    t->insert("KRITIKA");
    t->insert("RADHIKA");
    t->insert("NAWED");

    string str;
    string str2, str3;
    
    t->search("KARTIK") ? str = "The word was found!" : str = "The word does not exist!";
    t->search("NAWED") ? str2 = "The word was found!" : str2 = "The word does not exist!";

    cout << str << endl;
    cout << str2 << endl;

    cout << t->deleteWord("NAWED") << endl;

    t->search("NAWED") ? str3 = "The word was found!" : str3 = "The word does not exist!";
    cout << str3 << endl;

    return 0;
}