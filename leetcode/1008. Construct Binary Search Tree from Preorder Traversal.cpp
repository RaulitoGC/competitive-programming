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
  
    TreeNode* buildTreeUtil( vector<int>& preorder, int* preIndex, int key, int min, int max, int size ) {  
      if( *preIndex >= size )  
        return NULL;  
      
      TreeNode* root = NULL;  
  
      if( key > min && key < max ){  
          root = new TreeNode(key);  
          *preIndex = *preIndex + 1;
          if (*preIndex < size) {  
              root->left = buildTreeUtil( preorder, preIndex, preorder[*preIndex], min, key, size );
              if(*preIndex < size){
                root->right = buildTreeUtil( preorder, preIndex, preorder[*preIndex], key, max, size );  
              }
              
          }  
      }  
      return root;  
    }
  
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int size = preorder.size();
      int preIndex = 0;
      return buildTreeUtil(preorder, &preIndex, preorder[0], INT_MIN, INT_MAX, size);  
    }
};