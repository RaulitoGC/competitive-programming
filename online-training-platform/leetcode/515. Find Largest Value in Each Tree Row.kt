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
    fun largestValues(root: TreeNode?): List<Int> {
        if( root == null){
            return emptyList<Int>()
        }
        
        val queue = ArrayDeque<TreeNode>()
        queue.addLast(root)
        
        val result = mutableListOf<Int>()
        
        while(queue.isNotEmpty()){
            val size = queue.size
            var maxValue = Int.MIN_VALUE
            repeat(size){ _ ->
                val current = queue.first()
                queue.removeFirst()
                
                maxValue = max(maxValue, current.`val`)
                
                current.left?.let{
                    queue.addLast(it)
                }
                
                current.right?.let{
                    queue.addLast(it)
                }
                
            }
            result.add(maxValue)
        }
        
        
        return result
    }
    
}