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
    fun levelOrder(root: TreeNode?): List<List<Int>> {
        
        val result = mutableListOf<List<Int>>()
        val queue = ArrayDeque<TreeNode>()
        if(root != null){
            queue.addLast(root)
        }

        while(queue.isNotEmpty()){
            val size = queue.size
            val list = mutableListOf<Int>()
            repeat(size) {
                val node = queue.peekFirst()
                queue.removeFirst()
                list.add(node.`val`)

                node.left?.let{
                    queue.addLast(it)
                }

                node?.right?.let{
                    queue.addLast(it)
                }
            }
            result.add(list)
        }

        return result
    }
}