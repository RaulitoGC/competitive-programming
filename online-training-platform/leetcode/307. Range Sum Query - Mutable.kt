class NumArray(private val nums: IntArray) {
    
    private val acum = IntArray(nums.size + 1){
        0
    }
    
    init {
        acum[1] = nums[0]
        for(i in 2 until nums.size + 1){
            acum[i] = acum[i - 1] + nums[i - 1]
        }
    }

    fun update(index: Int, `val`: Int) {
        val current = nums[index]
        nums[index] = `val`
        val diff = `val` - current
        // println("diff -> $diff")
        for(i in index + 1 until acum.size) {
            acum[i] += diff
        }
    }

    fun sumRange(left: Int, right: Int): Int {
        // acum.forEach{
        //     print("$it ")
        // }
        // println()
        return acum[right + 1] - acum[left]
    }

}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = NumArray(nums)
 * obj.update(index,`val`)
 * var param_2 = obj.sumRange(left,right)
 */