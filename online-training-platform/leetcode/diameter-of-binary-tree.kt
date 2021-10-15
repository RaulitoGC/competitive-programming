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
  
    var maxPath = 0
  
    fun diameterOfBinaryTreeHelper(root: TreeNode?) :Int{
      if(root == null) {
        return 0
      }
      
      val left = diameterOfBinaryTreeHelper(root.left)
      val right = diameterOfBinaryTreeHelper(root.right)
      
      maxPath = Math.max(maxPath, left + right + 1)
      
      return Math.max(left + 1, right + 1)
    }
  
    fun diameterOfBinaryTree(root: TreeNode?): Int {
      diameterOfBinaryTreeHelper(root)
      return maxPath - 1
    }
}