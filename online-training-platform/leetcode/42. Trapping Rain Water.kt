class Solution {
    fun trap(height: IntArray): Int {
        val size = height.size
        val maxLeft = IntArray(size){0}
        val maxRight = IntArray(size){0}

        maxLeft[0] = height[0]
        for(i in 1 until size){
            maxLeft[i] = kotlin.math.max(height[i], maxLeft[i - 1])
        }

        maxRight[size - 1] = height[size - 1]
        for(i in size - 2 downTo 0){
            maxRight[i] = kotlin.math.max(height[i], maxRight[i + 1])
        }

        var result = 0
        for(i in 1 until size - 1){
            result += (kotlin.math.min(maxLeft[i], maxRight[i]) - height[i])
        }

        return result
    }
}