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
  
    long getValidPath(TreeNode* root, vector<int>& arr, int index, int size){
        if(root == NULL || index >= size) return false;
        
        if(root->left == NULL && root->right == NULL){
            return arr[index] == root->val && size - 1 == index;
        }
      
        bool left = getValidPath(root->left, arr, index + 1, size);
        bool right = getValidPath(root->right, arr, index + 1, size);
        return root->val == arr[index] && (left || right);
    }
  
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
      if(root == NULL) return false;
      
      TreeNode *left = root->left;
      TreeNode *right = root->right;
      
      if(left == NULL && right == NULL){
        return root->val == arr[0];
      }
      
      bool hl = getValidPath(left, arr, 1, arr.size());  
      bool hr = getValidPath(right, arr, 1, arr.size());
      return hl || hr;
    }
};

auto speedup=[](){
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();