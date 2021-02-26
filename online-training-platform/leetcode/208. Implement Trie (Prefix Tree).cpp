class Trie {
private:
    struct Node{
      
      unordered_map<char,Node*> children;
      bool isLeaf = false;
      Node(){}
    };
  
    Node *root = NULL;
public:
    /** Initialize your data structure here. */
    
  
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      
        Node *current =root;
      
        for(int i = 0; i < word.size() ; i++){
          Node *node = current->children[word[i]];
          if(!node){
            node = new Node();
            current->children[word[i]] = node;
          }
          current = node;
        }
        current->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      Node *current = root;
	    for(int i = 0 ; i < word.size() ; i++){
		    Node *node = current->children[word[i]];
		    if(!node) return false;
		    current = node;
	    }
      
	    return current->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *current = root;
	      for(int i = 0 ; i < prefix.size() ; i++){
		      Node *node = current->children[prefix[i]];
		      if(!node) return false;
		      current = node;
	      }
      
	      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
