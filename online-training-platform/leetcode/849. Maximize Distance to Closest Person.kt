class Solution {
    
    fun maxDistToClosest(seats: IntArray): Int {
        val size = seats.size
        val left = IntArray(size){
            -1
        }
        val right = IntArray(size) {
            -1
        }
        
        var idx = -1
        for(i in 0 until size) {
            if(seats[i] == 1){
                idx = i
                continue
            }
            
            if(idx != -1) {
              left[i] = i - idx  
            }
        }
        
        idx = -1
        for(i in size - 1 downTo 0) {
            if(seats[i] == 1){
                idx = i
                continue
            }
            
            if(idx != -1) {
              right[i] = idx - i
            }
        }
        
        // println(left.toList())
        // println(right.toList())
        
        var result = Int.MIN_VALUE
        repeat(size) {
            if(seats[it] == 0) {
                val l = left[it]
                val r = right[it]
                val minValue = when{
                    l != -1 && r != -1 -> min(l,r)
                    l != -1 && r == -1 -> l
                    r != -1 && l == -1 -> r
                    else -> 0
                }
                result = max(result, minValue)    
            }
        }
        
        return result
    }
}