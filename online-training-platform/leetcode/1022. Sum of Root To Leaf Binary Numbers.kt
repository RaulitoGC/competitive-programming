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
    
    private val numbers = mutableListOf<String>()
    
    
    private fun treeTraversal(root: TreeNode?, number: String){
        root?.let{
            
            val current = number + it.`val`.toString()
            
            if(it.left == null && it.right == null) {
                numbers.add(current)
                return
            }
            
            treeTraversal(it.left, current)
            treeTraversal(it.right, current)
        }
    }
    
    
    fun sumRootToLeaf(root: TreeNode?): Int {
        treeTraversal(root, "")
        
        var result = 0
        numbers.forEach {
            result += it.toInt(2)
        }
        
        return result
    }
}