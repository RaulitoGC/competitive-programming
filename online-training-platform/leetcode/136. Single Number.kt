class Solution {
    fun singleNumber(nums: IntArray): Int {
        var result = nums.first()
        for(idx in 1 until nums.size){
            result = (result xor nums[idx])
        }
        return result
    }
}