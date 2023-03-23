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
    fun zigzagLevelOrder(root: TreeNode?): List<List<Int>> {
        
        if(root == null){
            return listOf<List<Int>>()
        }

        val result = mutableListOf<List<Int>>()
        var isRight = true
        val queue = ArrayDeque<TreeNode>()
        queue.addLast(root)

        while(queue.isNotEmpty()){
            val size = queue.size
            val list = mutableListOf<Int>()
            repeat(size){
                val current = queue.peekFirst()
                queue.removeFirst()

                list.add(current.`val`)

                current.left?.let{
                    queue.add(it)
                }
                
                current.right?.let{
                    queue.add(it)
                }
            }
            
            result.add(if(isRight)list else list.reversed())
            isRight = !isRight
        }

        return result
    }
}