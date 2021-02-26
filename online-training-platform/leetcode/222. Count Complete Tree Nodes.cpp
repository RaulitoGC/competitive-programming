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
    
    int nodes(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int right = nodes(root->right);
        int left = nodes(root->left);

        return right + left + 1;
    }
    
    int countNodes(TreeNode* root) {
        return nodes(root);
    }
};
