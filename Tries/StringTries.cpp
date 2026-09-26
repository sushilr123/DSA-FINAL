/*
Implement a Trie (Prefix Tree) data structure that supports the following operations:
1. insert(word): Inserts a word into the trie.
2. search(word): Returns true if the word is in the trie, false otherwise.
3. startsWith(prefix): Returns true if there is a word in the trie that starts with the given prefix, false otherwise.
4. remove(word): Removes a word from the trie if it exists.
*/


#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isEndOfWord=false;
    }
};
class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* current=root;
        for(char c:word){
            int index=c-'a';
            if(current->children[index]==NULL){
                current->children[index]=new TrieNode();
            }
            current=current->children[index];
        }
        current->isEndOfWord=true;
    }
    bool search(string word){
        TrieNode* current=root;
        for(char c:word){
            int index=c-'a';
            if(current->children[index]==NULL){
                return false;
            }
            current=current->children[index];
        }
        return current->isEndOfWord;
    }
    void remove(string word){
        TrieNode* current=root;
        for(char c:word){
            int index=c-'a';
            if(current->children[index]==NULL){
                return;
            }
            current=current->children[index];
        }
        current->isEndOfWord=false;
    }
};
int main (){

return 0;
}