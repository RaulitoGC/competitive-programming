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
    
    
    TreeNode* invert(TreeNode* root) {
        
        if(root == NULL) return NULL;
        
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        
        root->left = invert(r);
        root->right = invert(l);
        
        return root;
    }
    
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        return invert(root);
    }
};
