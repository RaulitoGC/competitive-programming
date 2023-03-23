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

    fun buildNodeHelper(nums: IntArray, start: Int, end: Int): TreeNode? {

        if(start > end){
            return null
        }

        if(start == end){
            return TreeNode(nums[start])
        }

        if(start == end - 1){
            return TreeNode(nums[end]).apply{
                left = TreeNode(nums[start])
            }
        }

        val mid = start + (end - start) / 2
        val root = TreeNode(nums[mid]).apply{
            left = buildNodeHelper(nums, start, mid - 1)
            right = buildNodeHelper(nums, mid + 1, end)
        }

        return root
    }

    fun sortedArrayToBST(nums: IntArray): TreeNode? {
        val mid = nums.size / 2
        return TreeNode(nums[mid]).apply{
            left = buildNodeHelper(nums, 0, mid - 1)
            right = buildNodeHelper(nums, mid + 1, nums.size - 1)
        }
    }
}