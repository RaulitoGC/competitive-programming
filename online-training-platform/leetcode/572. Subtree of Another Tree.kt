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


    fun compare(root: TreeNode?, subRoot: TreeNode?): Boolean{
        if(root != null && subRoot != null){
            
            if(root.`val` != subRoot.`val`) return false

            if(compare(root.left, subRoot.left).not()) return false

            if(compare(root.right, subRoot.right).not()) return false

            return true

        }
        return root == null && subRoot == null
    }

    fun isSubtree(root: TreeNode?, subRoot: TreeNode?): Boolean {
        if(root != null && subRoot != null){
            val comp = compare(root, subRoot)
            return comp || isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot)
        }

        return false
    }
}