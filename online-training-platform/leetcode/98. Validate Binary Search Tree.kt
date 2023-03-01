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

    private val MAX_NODE_VALUE : Long = Int.MAX_VALUE.toLong() + 1
    private val MIN_NODE_VALUE : Long = Int.MIN_VALUE.toLong() - 1

    fun isValidBST(root: TreeNode?, maxNode: Long = MAX_NODE_VALUE, minNode: Long =  MIN_NODE_VALUE): Boolean {
        return root?.let{
            if( minNode >= it.`val`.toLong() || it.`val`.toLong() >= maxNode) {
                return false
            }

            return isValidBST(it.left, it.`val`.toLong(), minNode) && isValidBST(it.right, maxNode, it.`val`.toLong())
        } ?: true
    }
}