/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int maxSum = INT_MIN;
    int test = 0;
    
    int getMaxHeight(TreeNode* root, int height){
        if(root == NULL ) return 0;
        
        if(root->left == NULL && root->right == NULL) return 1;
        
        int left = getMaxHeight(root->left,0);
        int right = getMaxHeight(root->right,0);
        
        if(left + right > maxSum){
            maxSum = left + right;
        } 
        
        return max(left,right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int hl = 0;
        int hr = 0;
        if(root->left != NULL){
            hl = getMaxHeight(root->left,0);
        }
        
        if(root->right != NULL){
            hr = getMaxHeight(root->right,0);
        }
        return max(hl + hr,maxSum);
    }
};