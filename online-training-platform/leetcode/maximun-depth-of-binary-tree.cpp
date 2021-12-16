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
    
    int res = INT_MIN;
    
    void maxDepthHelper(TreeNode* root, int path) {
        if(root != nullptr) {
            
            if(root->left == nullptr && root->right == nullptr) {
                res = max(res, path);
                return;
            }
            
            maxDepthHelper(root->left, path + 1);
            maxDepthHelper(root->right, path + 1);
        }
    }
    
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        
        maxDepthHelper(root, 1);
        
        return res;
    }
};