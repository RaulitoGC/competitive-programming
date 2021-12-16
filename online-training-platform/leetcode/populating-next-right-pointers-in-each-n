/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == nullptr) {
            return nullptr;
        }
        
        queue<Node*> q;
        if(root->left != nullptr) {
            q.push(root->left);    
        } 
        
        if(root->right != nullptr) {
            q.push(root->right);    
        }
        
        while(!q.empty()) {
            int size = q.size();
            Node* prev = q.front();
            q.pop();
            
            if(prev->left != nullptr) {
                q.push(prev->left);
            }
            
            if(prev->right != nullptr) {
                q.push(prev->right);
            }
            
            for(int i = 1 ; i < size ; i++) {
                Node* next = q.front();
                q.pop();
                prev->next = next;
                prev = next;
                
                if(prev->left != nullptr) {
                    q.push(prev->left);
                }
            
                if(prev->right != nullptr) {
                    q.push(prev->right);
                }
            }
        }
        
        return root;
    }
};