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

    private val list = mutableListOf<Int>()

    private fun inorder(root: TreeNode?){
        root?.let{
            inorder(it.left)
            list.add(it.`val`)
            inorder(it.right)
        }
    }

    fun kthSmallest(root: TreeNode?, k: Int): Int {
        inorder(root)
        return list[k - 1]
    }
}