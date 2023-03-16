class Solution {
    fun subarraySum(nums: IntArray, k: Int): Int {
        
        var count = 0
        for(i in 0 until nums.size){
            var sum = 0
            for(j in i until nums.size){
                sum  += nums[j]
                if(sum == k){
                    count += 1
                }
            }
        }

        return count
    }
}