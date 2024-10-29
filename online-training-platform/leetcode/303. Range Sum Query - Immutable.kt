class NumArray(private val nums: IntArray) {

    private val acum = IntArray(nums.size){
        0
    }
    
    init{
        acum[0] = nums[0]
        for(i in 1 until nums.size){
            acum[i] = acum[i - 1] + nums[i]
        }
        
    }
    
    fun sumRange(left: Int, right: Int): Int {
        return if(left == 0) acum[right] else acum[right] - acum[left - 1]
    }

}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */