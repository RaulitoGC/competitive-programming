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
    
    void addOneRowHelper(TreeNode* root, int v, int d, int currentDepth){
        if(root != nullptr){
            if(d - 1 == currentDepth){
                TreeNode* left = new TreeNode(v);
                TreeNode* right = new TreeNode(v);
                left->left = root->left;
                right->right = root->right;
                root->left = left;
                root->right = right;
                return;
            }
            
            addOneRowHelper(root->left, v, d, currentDepth + 1);
            addOneRowHelper(root->right, v, d, currentDepth + 1);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if(d == 1){
           TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        addOneRowHelper(root,v,d,1);
        return root;
    }
};
