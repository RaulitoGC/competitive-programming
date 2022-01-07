/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    
    fun hasPathSum(root: TreeNode?, targetSum: Int): Boolean {
        if(root != null){
            if(targetSum - root.`val` == 0 && root.left == null && root.right == null){
                return true
            }
            return hasPathSum(root.left, targetSum - root.`val`) || hasPathSum(root.right, targetSum - root.`val`)
        }
        
        return false
    }
}