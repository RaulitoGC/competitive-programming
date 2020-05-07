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
    
    int mn = 0;
    int mx = 1000;
    
    int getHeight(TreeNode* root, int target, int anotherTarget, int height){
        
        if(root == NULL) return mx;
        
        if(root->val == target) return height;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        if(left != NULL){
            if(root->val == target && left->val == anotherTarget) return mx;
            if(root->val == anotherTarget && left->val == target) return mx;
        }
        
        if(right != NULL){
            if(root->val == target && right->val == anotherTarget) return mx;
            if(root->val == anotherTarget && right->val == target) return mx;
        }
        
        if(left != NULL && right != NULL){
            if(left->val == target && right->val == anotherTarget) return mx;
            if(left->val == anotherTarget && right->val == target) return mx;
        }
        
        int hl = getHeight(left, target, anotherTarget, height + 1);
        int hr = getHeight(right, target, anotherTarget, height + 1);
        
        
        return (hl < mx)? hl : hr;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(root == NULL) return false;
        if(root->val == x && root->val == y) return true;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        
        if(left != NULL && right != NULL){
            if(left->val == x && right->val == y) return false;
            if(left->val == y && right->val == x) return false;
        }
        if(left != NULL){
            if(root->val == x && left->val == y) return false;
            if(root->val == y && left->val == x) return false;
        }
        
        if(right != NULL){
            if(root->val == x && right->val == y) return false;
            if(root->val == y && right->val == x) return false;
        }
        
        int hl = 0, hr = 0;
        
        if(root->val == y) hr = 0;
        else hr = getHeight(right, y, x, 0);
        
        if(hr >= mx) hr = getHeight(left, y, x, 0);
        
        if(root->val == x) hl = 0;
        else hl = getHeight(right, x, y, 0);
        
        if(hl >= mx) hl = getHeight(left, x, y, 0);
        
        if(hl == mx || hr == mx) return false;
            
        return hl == hr;
    }
};