/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

 class Solution {
    fun lowestCommonAncestor(root: TreeNode?, p: TreeNode?, q: TreeNode?): TreeNode? {
        return root?.let{
            if(p == null || q == null ) return@let null
            val maxValue = kotlin.math.max(p.`val`, q.`val`)
            val minValue = kotlin.math.min(p.`val`, q.`val`)


            if(it.`val` > maxValue) {
                return@let lowestCommonAncestor(it.left, p, q)
            } else if( it.`val` < minValue) {
                return@let lowestCommonAncestor(it.right, p, q)
            } else {
                return@let it
            }
        }
    }
}