class Solution {
    fun numSubarrayProductLessThanK(nums: IntArray, k: Int): Int {

        if(k <= 1){
            return 0
        }

        var product = 1; var result = 0
        var start = 0; var end = 0
        
        for(end in 0 until nums.size){
            product *= nums[end]
            while(product >= k){
                product /= nums[start]
                start += 1
            }
            result += (end - start + 1)
        }

        return result
    }
}