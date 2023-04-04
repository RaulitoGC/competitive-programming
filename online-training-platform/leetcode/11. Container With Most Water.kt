class Solution {
    fun maxArea(height: IntArray): Int {
        var start = 0; var end = height.size - 1

        var area = 0
        while(start < end){
            area = kotlin.math.max(area, (end - start) * kotlin.math.min(height[end], height[start]))

            if(height[start] <= height[end]){
                start += 1
            } else{
                end -= 1
            }
        }

        return area
    }
}