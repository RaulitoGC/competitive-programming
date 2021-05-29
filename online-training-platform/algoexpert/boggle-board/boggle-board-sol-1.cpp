#include <vector>
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

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isValidPosition(int x, int y, int n, int m);
vector<pair<int,int>> getNeighbors(int x, int y,vector<vector<char>> board);
void traverse(int x, int y, vector<vector<char>> board, TrieNode* trieNode,
						 vector<vector<bool>> &visited, unordered_set<string> &finalWords);


vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
	
	int n = board.size();
	int m = board[0].size();
	
	Trie* trie = new Trie();
	
	for(int i = 0 ; i < words.size() ; i++){
		trie->addWord(words[i]);
	}
	
	unordered_set<string> finalWords;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0; j < m ; j++){
			traverse(i, j, board, trie->root, visited, finalWords);
		}
	}
		
  return vector<string>(finalWords.begin(), finalWords.end());
}

void traverse(int x, int y, vector<vector<char>> board, TrieNode* trieNode,
						 vector<vector<bool>> &visited, unordered_set<string> &finalWords){
	
	if(visited[x][y]){
		return;
	}
	
	char letter = board[x][y];
	
	if(trieNode->children.find(letter) == trieNode->children.end()){
		return;
	}
	
	visited[x][y] = true;
	trieNode = trieNode->children[letter];
	if(trieNode->children.find('*') != trieNode->children.end()){
		finalWords.insert(trieNode->word);
	}
	
	vector<pair<int,int>> neighbors = getNeighbors(x, y, board);
	for(int i = 0 ; i < neighbors.size() ; i++){
		traverse(neighbors[i].first, neighbors[i].second, board, trieNode, visited, finalWords);
	}
	
	visited[x][y] = false;
}

vector<pair<int,int>> getNeighbors(int x, int y,vector<vector<char>> board){
	vector<pair<int, int>> res;
	
	int n = board.size();
	int m = board[0].size();
	for(int i = 0 ; i < 8 ; i++){
		if(isValidPosition(x + dx[i],y + dy[i], n, m)){
			res.push_back(make_pair(x + dx[i], y + dy[i]));
		}
	}
	
	return res;
}

bool isValidPosition(int x, int y, int n, int m){
	return x >= 0 && x < n && y >= 0 && y < m;
}

