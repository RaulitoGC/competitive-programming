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

    private val result = mutableListOf<List<Int>>()

    private fun pathSumHelper(root: TreeNode?, target: Int, currentList: List<Int>, currentSum: Int){

        if(root == null){
            return
        }

        val currentValue = root.`val`
        if(currentSum + currentValue == target && root.left == null && root.right == null){
            result.add(currentList + listOf(currentValue))
        }

        pathSumHelper(root.left, target, currentList + listOf(currentValue), currentSum + currentValue)
        pathSumHelper(root.right, target, currentList + listOf(currentValue), currentSum + currentValue)

    }

    fun pathSum(root: TreeNode?, targetSum: Int): List<List<Int>> {
        pathSumHelper(root, targetSum, listOf<Int>(), 0)
        return result
    }
}