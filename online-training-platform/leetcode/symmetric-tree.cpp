/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isSymmetricHelper(TreeNode* first, TreeNode* second) {
        
        if(first == nullptr && second == nullptr) {
            return true;
        }
        
        if(first != nullptr && second == nullptr){
            return false;
        }
        
        if(first == nullptr && second != nullptr){
            return false;
        }
        
        if(first->val != second->val) {
            return false;
        }
        
        return isSymmetricHelper(first->right, second->left) && 
            isSymmetricHelper(first->left, second->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root->left != nullptr && root->right == nullptr){
            return false;
        }
        
        if(root->left == nullptr && root->right != nullptr){
            return false;
        }
        
        return isSymmetricHelper(root->left, root->right);
    }
};