class Solution {
    // Time: O(nLogn)
    // Space: O(n)
    fun heightChecker(heights: IntArray): Int {
        val sorted = heights.sorted()
        var result = 0
        for(i in 0 until heights.size){
            if(heights[i] != sorted[i]){
                result += 1
            }
        }

        return result
    }
}