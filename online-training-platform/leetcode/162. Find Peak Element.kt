class Solution {
    fun findPeakElement(nums: IntArray): Int {
        for(idx in 0 until nums.size - 1){
            if(nums[idx] > nums[idx + 1]){
                return idx
            }
        }
        return nums.size - 1
    }
}