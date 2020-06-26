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
    
    void sumLeaf(TreeNode* root,string number, int& total){
        if(root == NULL) return;
        number = number + to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            total += stoi(number);
            return;
        }
        
        sumLeaf(root->left,number, total);
        sumLeaf(root->right,number, total);
    }
    
    
    int sumNumbers(TreeNode* root) {
        int total = 0;
        sumLeaf(root,"", total);
        return total;
    }
};
