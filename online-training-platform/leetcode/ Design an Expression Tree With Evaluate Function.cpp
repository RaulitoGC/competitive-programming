/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
  public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
};

class AENode : public Node{
  public:
  
    AENode* left;
    AENode* right;
    string val;
    
    AENode(string val){
      this->val = val;
    }

    AENode(string val, AENode* left, AENode* right){
      this->val = val;
      this->left = left;
      this->right = right;
    }

    int evaluate() const{
      if(this->left == nullptr && this->right == nullptr){
        return stoi(this->val);
      }
      
      
      int left = this->left->evaluate();
      int right = this->right->evaluate();
      cout << left << " -- " << right << endl;
      cout << this->val << endl;
      if(this->val == "+"){
        return left + right;
      }else if(this->val == "-"){
        return left - right;
      }else if(this->val == "*"){
        return left*right;
      }else if(this->val == "/"){
        return left/right;
      } 
      
      return -1;
    }
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
  
    bool isOperator(string str){
      return str == "+" || str == "-" || str == "*" || str == "/";
    }
  
    Node* buildTree(vector<string>& postfix) {
      stack<AENode*> st;
      int n = postfix.size();
      for(int idx = 0 ; idx < n ; idx++){
        
        AENode* node = new AENode(postfix[idx], nullptr, nullptr);
        
        if(isOperator(postfix[idx])){
          node->right = st.top();
          st.pop();
          node->left = st.top();
          st.pop();
        }
        
        st.push(node);
      }
      
      return st.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */