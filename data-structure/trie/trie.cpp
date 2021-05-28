#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode *> children;
  string word = "";
};

class Trie {
public:
  TrieNode *root;
  char endSymbol;

  Trie(){
    this->root = new TrieNode();
    this->endSymbol = '*';
  }

  void addWord(string str){
    TrieNode* current = root;
    for(int i = 0 ; i < str.size() ; i++){
      if(current->children.find(str[i]) == current->children.end()){
        TrieNode* newNode = new TrieNode();
        current->children[str[i]] = newNode;
      }
      current = current->children[str[i]];
    }
    current->children[endSymbol] = nullptr;
    current->word = str;
  }
};

