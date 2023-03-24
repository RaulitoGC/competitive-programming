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
    fun rightSideView(root: TreeNode?): List<Int> {
        
        if(root == null){
            return listOf<Int>()
        }

        val result = mutableListOf<Int>()
        val queue = ArrayDeque<TreeNode>()
        queue.addLast(root)

        while(queue.isNotEmpty()){
            val size = queue.size
            repeat(size){ idx ->
                val current = queue.peekFirst()
                if(idx == 0){
                    result.add(current.`val`)
                }
                
                queue.removeFirst()

                current.right?.let{
                    queue.addLast(it)
                }

                current.left?.let{
                    queue.addLast(it)
                }
            }
        }

        return result
    }
}