/*
when xor related problem are there we can use bit tries to solve the problem efficiently.

bit trie is a trie data structure that is used to store binary representations of numbers. Each node in the trie represents a bit (0 or 1) and has two children, one for each possible bit value. The path from the root to a leaf node represents the binary representation of a number.

logic:
1. To insert a number into the bit trie, we start from the root and for each bit of the number (from the most significant bit to the least significant bit), we check if the corresponding child node exists. If it does not exist, we create a new node. We then move to the child node and repeat this process until we have processed all bits of the number.
2. To search for a number in the bit trie, we follow the same process as insertion, but instead of creating new nodes, we check if the corresponding child node exists. If at any point we encounter a null child node, it means that the number is not present in the trie. If we successfully traverse all bits and reach a leaf node, it means that the number is present in the trie.


*/

#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* children[2];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0;i<2;i++){
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
    void insert(int num){
        TrieNode* current=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(current->children[bit]==NULL){
                current->children[bit]=new TrieNode();
            }
            current=current->children[bit];
        }
        current->isEndOfWord=true;
    }
    bool search(int num){
        TrieNode* current=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(current->children[bit]==NULL){
                return false;
            }
            current=current->children[bit];
        }
        return current->isEndOfWord;
    }
}; 
int main (){

return 0;
}