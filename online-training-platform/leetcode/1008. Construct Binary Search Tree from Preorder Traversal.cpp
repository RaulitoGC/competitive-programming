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
  
    TreeNode* getBst( vector<int>& preorder, int left, int right){
        
        if( left > right) return NULL;

        TreeNode* node = new TreeNode(preorder[left]);
        int i = left + 1;
        
        for(; i < preorder.size() ; i++){
            if(node->val <= preorder[i]) break;
        }
        
        node->left = getBst(preorder, left + 1, i-1);    
        node->right = getBst( preorder, i, right);    
        
        return node;  
    }
  
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return getBst(preorder, 0, preorder.size() - 1);  
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
