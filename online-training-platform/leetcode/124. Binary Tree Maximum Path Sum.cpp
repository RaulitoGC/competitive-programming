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
  
    long maxSum = INT_MIN + 1;
  
    long maxL(long a,long b){
      return (a > b)? a : b;
    }
    
    long getMaxHeight(TreeNode* root){
        if(root == NULL ) return 0;
        
        if(root->left == NULL && root->right == NULL) return root->val;
        
        int left = getMaxHeight(root->left);
        int right = getMaxHeight(root->right);
        
        long m1 = maxL(root->val, maxL(root->val + left,root->val +right));
        long m2 = maxL(m1, root->val + left + right);
        long m3;
        if(root->left == NULL && root->right == NULL){
          m3 = m2;
        }else if(root->left != NULL && root->right == NULL){
          m3 = maxL(m2,left);
        }else if(root->left == NULL && root->right != NULL){
          m3 = maxL(m2,right);
        }else{
          m3 = maxL(m2, maxL(left,right));
        }
        
        if(m3 > maxSum){
            maxSum = m3;
        } 
        
        return m1;
    }
  
    int maxPathSum(TreeNode* root) {
      if(root == NULL) return 0;
      
        long long hl = INT_MIN;
        long long hr = INT_MIN;
      
        int v = root->val;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
      
        if(left == NULL && right == NULL){
          return v;
        }
        
        if(left != NULL){
            hl = getMaxHeight(left);
        }
        
        if(right != NULL){
            hr = getMaxHeight(right);
        }
         
        int m1 = maxL(v,maxL(hr,hl));
        int m2 = maxL(maxSum, maxL(v+hl,v+hr));
        
        return maxL(hl + hr + v, maxL(m1,m2));
    }
};