#include <vector>
using namespace std;

struct Node{
	bool word;
	unordered_map<char, Node*> children;
};

class Trie{
	public:
		Node* root;
		
	Trie(){
		this->root = new Node();
	}
	
	void insert(string word){
		Node* current = this->root;
		int n = word.size();
		for(int i = 0 ; i < n ; i++){
			if(current->children.find(word[i]) == current->children.end()){
				Node* node = new Node();
				current->children[word[i]] = node;
			}
			current = current->children[word[i]];
		}
		current->word = true;
	}
	
	bool find(string word){
		Node* current = this->root;
		int n = word.size();
		
		for(int i = 0 ; i < n ; i++){
			if(current->children.find(word[i]) == current->children.end()){
				return false;
			}
			current = current->children[word[i]];
		}
		cout << "res ->" << current->word << endl;
		return current != NULL && current->word;
	}
};

bool findSmallString(Trie* trie, int startIdx, string str);

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
  
	int n = smallStrings.size();
	Trie* trie = new Trie();
	
	for(int i = 0 ; i < n ; i++){
		trie->insert(smallStrings[i]);
	}
	
	unordered_set<string> wordsFound;
	int m = bigString.size();
	for(int i = 0 ; i < m ; i++){
		for(int j = 1 ; j <= m ; j++){
			string currentWord = bigString.substr(i, j);
			cout << "current -> " << currentWord << endl;
			if(trie->find(currentWord)){
				wordsFound.insert(currentWord);
			}
		}
	}
	
	vector<bool> res;
	for(int i = 0 ; i < n ; i++){
		res.push_back(wordsFound.find(smallStrings[i]) != wordsFound.end());
	}
	
  return res;
}

