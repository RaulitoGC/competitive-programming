class Solution {

    // Time complexity = O(n)
    // Space Complexity = O(1)
    fun runningSum(nums: IntArray): IntArray {
        for(i in 1 until nums.size){
            nums[i] += nums[i - 1]
        }
        return nums
    }
}