class Solution {
    fun merge(intervals: Array<IntArray>): Array<IntArray> {
      val times = mutableListOf<Pair<Int, Int>>()
      
      for(interval in intervals){
        times.add(Pair(interval[0], interval[1]))
      }
      
      val sorted = times.sortedWith(compareBy(
        { it.first },
        { it.second })
      )
      
      val res = mutableListOf<IntArray>()
      
      val n = sorted.size
      var (startPrev, endPrev) = sorted[0]
      for(idx in (1..sorted.lastIndex)){
        val (start, end) = sorted[idx]
        if( startPrev <= start && start <= endPrev){
          endPrev = maxOf(endPrev, end)
        }else{
          res.add(intArrayOf(startPrev, endPrev))
          startPrev = start
          endPrev = end
        }
      }
      
      res.add(intArrayOf(startPrev, endPrev))
      
      return res.toTypedArray()
    }
}