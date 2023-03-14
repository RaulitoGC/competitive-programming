class Solution {

    fun minHelper(a: Int, b: Int) = kotlin.math.min(a,b)
    fun maxHelper(a: Int, b: Int) = kotlin.math.max(a,b)

    fun merge(intervals: Array<IntArray>): Array<IntArray> {
        val sorted = intervals.sortedBy{it[0]}.toMutableList()
        val result = mutableListOf<IntArray>()
        
        var idx = 1
        result.add(intArrayOf(sorted[0][0], sorted[0][1]))

        while(idx < sorted.size) {
            val first = result.last()
            val second = sorted[idx]

            if(second[0] <= first[1]){
                val minValue = minHelper(first[0], second[0])
                val maxValue = maxHelper(first[1], second[1])
                result.removeAt(result.size - 1)
                result.add(intArrayOf(minValue, maxValue))
            } else {
                result.add(intArrayOf(second[0], second[1]))
            }
            idx += 1
        }
        return result.toTypedArray()
    }
}