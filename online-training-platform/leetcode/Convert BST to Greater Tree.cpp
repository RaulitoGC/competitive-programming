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
    
    int total = 0;
    
    int convertBSTHelper(TreeNode* root){

        if(root != nullptr){
            convertBSTHelper(root->left);
            int oldValue = root->val;
            root->val = total;
            total -= oldValue;
            convertBSTHelper(root->right);
        }
        return 0;
    }
    
    void getTotalSum(TreeNode* root) {
        if(root != nullptr){
            total += root->val;
            getTotalSum(root->left);
            getTotalSum(root->right);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
        getTotalSum(root);
        convertBSTHelper(root);
        return root;
    }
};
