class Solution {
    fun eraseOverlapIntervals(intervals: Array<IntArray>): Int {
        if(intervals.size == 0) {
            return 0
        }

        val sorted = intervals.sortedBy{it.last()}

        val size = intervals.size
        var prev = 0; var result = 0
        for(idx in 1 until size){
            if(sorted[idx][0] < sorted[prev][1]){
                if(sorted[prev][1] > sorted[idx][1]) {
                    prev = idx
                }
                result += 1
            } else{
                prev = idx
            }
        }


        return result
    }
}