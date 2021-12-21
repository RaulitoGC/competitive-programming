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
    bool isValidBST(TreeNode* root) {
        
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        
        if(root->left != NULL && root->right == NULL){
            return (root->left)->val < root->val;
        }
        
        if(root->left == NULL && root->right != NULL){
            return root->val < (root->right)->val;
        }
        
        int left = (root->left)->val;
        int right = (root->right)->val;
        int current = root->val;
        return left < current && current < right && isValidBST(root->left) && isValidBST(root->right); 
        
    }
};
