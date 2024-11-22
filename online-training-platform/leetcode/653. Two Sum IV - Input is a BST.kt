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
    
    private val numbers = mutableListOf<Int>()
    
    // n: number of nodes in the tree
    // Time : O(n)
    // Space: O(n)
    private fun preOrderTraversal(root: TreeNode?) {
        root?.let{
            preOrderTraversal(it.left)
            numbers.add(it.`val`)
            preOrderTraversal(it.right)
        }
    }
    
    
    fun findTarget(root: TreeNode?, k: Int): Boolean {
        preOrderTraversal(root)
        
        var start = 0; var end = numbers.size - 1
        while(start < end){
            val sum = numbers[start] + numbers[end]
            if(sum < k){
                start += 1
            } else if( sum > k) {
                end -= 1
            } else {
                return true
            }
        }
        
        return false
    }
}