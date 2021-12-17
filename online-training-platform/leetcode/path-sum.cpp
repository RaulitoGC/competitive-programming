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
    
    bool res = false;
    
    void hasPathSumHelper(TreeNode* root, int& targetSum, int currentSum) {
        if(root != nullptr) {
            if(root->left == nullptr && root->right == nullptr) {
                currentSum += root->val;
                if(targetSum == currentSum) {
                    res = true;
                }
                return;
            }
            
            hasPathSumHelper(root->left, targetSum, currentSum + root->val);
            hasPathSumHelper(root->right, targetSum, currentSum + root->val);
        }
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        hasPathSumHelper(root, targetSum, 0);
        return res;
    }
};