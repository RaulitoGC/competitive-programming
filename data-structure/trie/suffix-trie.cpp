#include<bits/stdc++.h>
using namespace std;


class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieFrom(string str) {
		int sz = str.size();
		for(int i = 0 ; i < sz ; i++){
			helperPopulateSuffixTrieFrom(str, sz, i);	
		}
  }
	
	void helperPopulateSuffixTrieFrom(string str, int sz, int i){
		TrieNode* current = this->root;
		for(int j = i ; j < sz ; j++){
			if(current->children.find(str[j]) == current->children.end()){
				TrieNode* newNode = new TrieNode();
				current->children[str[j]] = newNode;
			}
			current = current->children[str[j]];
		}
		current->children[endSymbol] = NULL;
	}

  bool contains(string str) {
		int sz = str.size();
		TrieNode* current = root;
    for(int i = 0; i < sz ; i++){
				if(current->children.find(str[i]) != current->children.end()){
					current = current->children[str[i]];
				}else{
					return false;
				}
		}
    return current->children.find(endSymbol) != current->children.end();
  }
};

