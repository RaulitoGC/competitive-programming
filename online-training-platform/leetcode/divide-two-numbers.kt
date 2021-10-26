class Solution {
  
    val HALF_MIN_VALUE = -1073741824
  
    fun divide(dividend: Int, divisor: Int): Int {
        if(dividend == Int.MIN_VALUE && divisor == -1){
          return Int.MAX_VALUE
        }
        
        var negatives = 2
        var divdnd = dividend
        var divsr = divisor
      
        if(divdnd > 0) {
          negatives--
          divdnd = -divdnd
        }
        
        if(divsr > 0) {
          negatives--
          divsr = -divsr
        }
        
        var q = 0

        while(divdnd <= divsr){
          var powerOfTwo = -1
          var value = divsr
          
          while(value >= HALF_MIN_VALUE && value + value >= divdnd) {
            value += value
            powerOfTwo += powerOfTwo
          }
          
          q += powerOfTwo
          divdnd -= value
          println(divdnd)
          println(divsr)
          println(divdnd-divsr)
        }
      
        
        if(negatives != 1) {
          q = -q
        }
        
        return q
    }
}