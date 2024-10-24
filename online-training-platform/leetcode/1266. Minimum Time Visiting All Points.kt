class Solution {
    
    private fun getMinDistance(point1: IntArray, point2: IntArray): Int {
        val diffX = abs(point1[0] - point2[0])
        val diffY = abs(point1[1] - point2[1])
        
        return if(diffX == 0 || diffY == 0){
            if(diffX != 0) diffX else diffY
        } else if(diffX == diffY){
            diffX
        } else {
            val maxDiff = max(diffX, diffY)
            val minDiff = min(diffX, diffY)
            
            min(maxDiff,minDiff) + (maxDiff - minDiff)
        }
    }
    
    fun minTimeToVisitAllPoints(points: Array<IntArray>): Int {
        var result = 0
        
        for(i in 1 until points.size){
            result += getMinDistance(points[i - 1], points[i])
        }
        
        return result
    }
}