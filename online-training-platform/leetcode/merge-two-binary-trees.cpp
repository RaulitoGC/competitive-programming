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
    
    int getValue(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 != nullptr){
            return root2->val;
        }
        
        if(root1 != nullptr && root2 == nullptr) {
            return root1->val;
        }
        
        return root1->val + root2->val;
    }
    
    TreeNode* mergeTreesHelper(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        
        int current = getValue(root1, root2);
        TreeNode* root = new TreeNode(current);
        
        // left
        if(root1 == nullptr && root2 != nullptr) {
            root->left = mergeTreesHelper(nullptr, root2->left);
            root->right = mergeTreesHelper(nullptr, root2->right);
        } else if(root1 != nullptr && root2 == nullptr) {
            root->left = mergeTreesHelper(root1->left, nullptr);
            root->right = mergeTreesHelper(root1->right, nullptr);
        } else {
            root->left = mergeTreesHelper(root1->left, root2->left);
            root->right = mergeTreesHelper(root1->right, root2->right);
        }
        
        
        return root;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return mergeTreesHelper(root1, root2);
    }
};