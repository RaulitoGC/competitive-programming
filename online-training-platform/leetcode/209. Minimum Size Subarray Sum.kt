class Solution {
    fun minSubArrayLen(target: Int, nums: IntArray): Int {
        
        var accum = 0; var start = 0; var end = 0
        var result = Int.MAX_VALUE
        
        while(end < nums.size){
            accum += nums[end]

            while(start < nums.size && accum - nums[start] >= target) {
                accum -= nums[start]
                start += 1
            }

            //println("$start - $end  | $accum")
            if(accum >= target){
                result = kotlin.math.min(result, end - start + 1)
            }
            end += 1
        }

        return if(result == Int.MAX_VALUE) 0 else result
    }
}