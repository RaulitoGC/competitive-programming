class Solution {

    private fun helper( nums: IntArray){
        nums.forEach{
            print(" ${it}")
        }
        println()
    }

    fun firstMissingPositive(nums: IntArray): Int {
        val isOnePresent = nums.any{ it == 1}

        if(isOnePresent.not()){
            return 1
        }

        val size = nums.size
        for(idx in 0 until size){
            if(nums[idx] > size || nums[idx] <= 0){
                nums[idx] = 1
            }
        }

        for(idx in 0 until size){
            val i = kotlin.math.abs(nums[idx])

            if(i == size){
                nums[0] = - kotlin.math.abs(nums[0])
            } else {
                nums[i] = - kotlin.math.abs(nums[i])
            }
        }

        for(idx in 1 until size){
            if(nums[idx] > 0) {
                return idx
            }
        }

        return if(nums[0] > 0) size else size + 1
    }
}