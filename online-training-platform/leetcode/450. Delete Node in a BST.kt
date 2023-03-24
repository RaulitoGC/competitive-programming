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

    private fun getSuccessor(root: TreeNode?): Int {
        var node: TreeNode? = root?.right
        while(node?.left != null){
            node = node?.left
        }
        return node!!.`val`
    }

    private fun getPredecesor(root: TreeNode?): Int {
        var node: TreeNode? = root?.left
        while(node?.right != null){
            node = node?.right
        }
        return node!!.`val`
    }


    fun deleteNode(root: TreeNode?, key: Int): TreeNode? {
        if(root == null){
            return null
        }
        var node = root
        if(key < node.`val`){
            node.left = deleteNode(node.left, key)
        } else if(key > root.`val`) {
            node.right = deleteNode(node.right, key)
        } else {

            if(node.left == null && node.right == null){
                node = null
            } else if(node.right != null){
                node.`val` = getSuccessor(node)
                node.right = deleteNode(node.right, node.`val`)
            } else {
                node.`val` = getPredecesor(node)
                node.left = deleteNode(node.left, node.`val`)
            }
        }

        return node
    }
}