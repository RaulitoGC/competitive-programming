class Solution {
    fun sortColors(nums: IntArray): Unit {
        var zeros = 0
        var ones = 0
        var twos = 0

        for(idx in 0 until nums.size) {
            if(nums[idx] == 0){
                zeros += 1
            } else if(nums[idx] == 1) {
                ones += 1
            } else {
                twos += 1
            }
        }

        var idx = 0
        while( zeros > 0){
            nums[idx] = 0
            idx += 1
            zeros -= 1
        }

        while( ones > 0){
            nums[idx] = 1
            idx += 1
            ones -= 1
        }

        while( twos > 0){
            nums[idx] = 2
            idx += 1
            twos -= 1
        }
    }
}