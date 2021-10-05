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
      var copiedChars = 0
      var readChars = 4
      val buf4 = CharArray(4)
      
      while(copiedChars < n && readChars == 4){
        readChars = read4(buf4)
        
        for(i in 0 until readChars){
          if(copiedChars == n){
            return copiedChars
          }
          buf[copiedChars] = buf4[i]
          copiedChars += 1
        }
      }
      
      return copiedChars
    }
}
