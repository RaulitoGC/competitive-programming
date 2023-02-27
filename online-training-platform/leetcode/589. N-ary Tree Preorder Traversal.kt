/**
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var children: List<Node?> = listOf()
 * }
 */

 class Solution {

    private val result = mutableListOf<Int>()

    private fun preorderHelper(root: Node?) {
        root?.let{
            result.add(it.`val`)
            it.children.forEach{ child ->
                preorderHelper(child)
            }
        }
    }

    fun preorder(root: Node?): List<Int> {
        preorderHelper(root)
        return result
    }
}