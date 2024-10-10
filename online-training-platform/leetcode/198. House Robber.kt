class Solution {
    fun rob(nums: IntArray): Int {
        val size = nums.size
        if(size == 1){
            return nums.first()
        }
        
        if(size == 2){
            return max(nums[0], nums[1])
        }
        
        if(size == 3){
            return max(nums[0] + nums[2], nums[1])
        }
        
        val acum = IntArray(size){
            0
        }
        
        acum[0] = nums[0]
        acum[1] = nums[1]
        acum[2] = acum[0] + nums[2]
        
        for(i in 3 until size){
            acum[i] = max(acum[i - 2] + nums[i], acum[i - 3] + nums[i])
        }
        
        return max(acum[size - 1], acum[size - 2])
    }
}