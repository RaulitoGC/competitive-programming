class Solution {
    fun intervalIntersection(firstList: Array<IntArray>, secondList: Array<IntArray>): Array<IntArray> {
        if(firstList.isEmpty() || secondList.isEmpty()){
            return Array<IntArray>(0){
                intArrayOf()
            }
        }

        var i = 0; var j = 0
        var firstSize = firstList.size; var secondSize = secondList.size

        val result = mutableListOf<IntArray>()
        
        while(i < firstSize && j < secondSize) {
            val iStart = firstList[i][0]; val iEnd = firstList[i][1]
            val jStart = secondList[j][0]; val jEnd = secondList[j][1]

            val maxStart = kotlin.math.max(iStart, jStart)
            val minEnd = kotlin.math.min(iEnd, jEnd)

            if(maxStart <= minEnd){
                result.add(intArrayOf(maxStart, minEnd))
            }

            if(minEnd == iEnd) i += 1 else j += 1
        }

        return result.toTypedArray()
    }
}