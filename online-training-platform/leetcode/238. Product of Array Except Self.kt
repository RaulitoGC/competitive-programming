class Solution {
    fun productExceptSelf(nums: IntArray): IntArray {
        val size = nums.size
        val right = MutableList<Int>(size){1}
        val left = MutableList<Int>(size){1}

        right[0] = nums[0]
        for(idx in 1 until size){
            right[idx] = nums[idx]*right[idx-1]
        }

        left[size - 1] = nums[size - 1]
        for(idx in size - 2 downTo 0){
            left[idx] = nums[idx]*left[idx + 1]
        }

        val result = IntArray(size){1}
        result[0] = left[1]
        result[size - 1] = right[size - 2]

        // println(left)
        // println(right)
        // println(result.toList())
        for(idx in 1 until (size - 1)){
            result[idx] = left[idx + 1]*right[idx - 1]
        }

        return result
    }
}