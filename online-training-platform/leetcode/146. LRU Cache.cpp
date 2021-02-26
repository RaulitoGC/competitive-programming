class LRUCache {
private:
  struct Node{
    int value;
    int key;
    Node *prev;
    Node *next;
    Node() : value(-1),key(-1),prev(NULL),next(NULL){}
  };
  
  unordered_map<int, Node*> umap;
  Node *head = new Node();
  Node *tail = new Node();
public:
    
    int size;
  
    LRUCache(int capacity)  {
      size = capacity;
      head->next = tail;
      tail->prev = head;
    }
    
    int get(int key) {

      int result = -1;
      if(umap.count(key) > 0){
        Node *node = umap[key];
        result = node->value;
        remove(node);
        add(node);  
      }
      return result;
    }
  
    void remove(Node *node){
      
      Node *next = node->next;
      Node *prev = node->prev;
      
      if(prev != NULL){
        prev->next = next;
      }      
      node->prev = NULL;
      
      if(next != NULL){
        next->prev = prev;  
      }
      
      node->next = NULL;
      umap.erase(node->key);
      node = NULL;
      
    }
  
    void add(Node *node){
      
      Node *prev = tail->prev;
      
      node->next = tail;
      node->prev = prev;
      
      prev->next = node;
      tail->prev = node;
      
      umap[node->key] = node;
      
    }
    
    void put(int key, int value) {
      if(umap.count(key) > 0){
        Node *node = umap[key];
        node->value = value;
        node->key = key;
        remove(node);
        add(node);
      }else{
        Node *node = new Node();
        node->value = value;
        node->key = key;
        if(umap.size() == size){
          Node *r = head->next;
          remove(r);  
        }
        add(node);
      }
    }
};

auto speedup=[](){
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */