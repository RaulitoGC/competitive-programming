class Solution {
    fun rob(nums: IntArray): Int {
        val size = nums.size
        
        if(size <= 2){
            return nums.max()
        }
        
        val acumNumber = IntArray(size){
            0
        }

        acumNumber[0] = nums[0]
        acumNumber[1] = nums[1]
        acumNumber[2] = nums[2] + nums[0]
        var result = max(acumNumber[1], acumNumber[2])
        
        for(i in 3 until size){
            acumNumber[i] = max(acumNumber[i-2] + nums[i], acumNumber[i - 3] + nums[i])
            result = max(result, acumNumber[i])
        }
        
        
        return result
    }
}