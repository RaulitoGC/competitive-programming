/**
* The read4 API is defined in the parent class Reader4.
* fun read4(buf4:CharArray): Int {}
*/

class Solution:Reader4() {
    /**
      * @param buf Destination buffer
      * @param n Number of characters to read
      * @return The number of actual characters read
      */
    override fun read(buf:CharArray, n:Int): Int {
        
        val iterations = (n / 4) + 1
        var idx = 0
        repeat(iterations) {
            val buf4 = CharArray(4){
                ' '
            }
            val current = read4(buf4)
            repeat(current){ i ->
                if(buf4[i] != ' ' && idx < n) {
                    buf[idx] = buf4[i]
                    idx += 1    
                }
            }
        }
        return idx
    }
}