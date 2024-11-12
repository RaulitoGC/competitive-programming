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
    
    fun executeComparison(root: TreeNode?, subRoot: TreeNode?): Boolean {
        return root?.let{
            if(subRoot == null){
                return false
            }
            if(it.`val` == subRoot?.`val`){
                val left = executeComparison(it.left, subRoot?.left)
                val right = executeComparison(it.right, subRoot?.right)
                (left && right)
            } else {
                false
            }
        } ?: (subRoot == null)
    }
    
    fun isSubtree(root: TreeNode?, subRoot: TreeNode?): Boolean {
        var result = false
        
        val stack = ArrayDeque<TreeNode?>()
        stack.addLast(root)
        while(stack.isNotEmpty()) {
            val current = stack.last()
            stack.removeLast()
            //println("val -> ${current?.`val`}  ---- ${subRoot?.`val`}")
            if(current?.`val` == subRoot?.`val`){
                val currentResult = executeComparison(current, subRoot)
                //println("curren result $currentResult")
                result = result || currentResult
            }
            
            current?.left?.let{
                stack.addLast(it)
            }
            
            current?.right?.let{
                stack.addLast(it)
            }
        }
        
        
        return result
    }
}