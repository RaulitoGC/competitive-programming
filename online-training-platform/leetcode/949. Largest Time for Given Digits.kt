class Solution {
    
    
    private val indices = setOf(0,1,2,3)
    private var maxHours = 0
    private var maxMinutes = 0
    private var result = ""
    
    private fun isMajorValidHour(hour: Int): Boolean {
        return hour > maxHours && hour >= 0 && hour < 24
    }
    
    private fun isValidMinutes(minutes: Int): Boolean {
        return minutes >= 0 && minutes < 60
    }
    
    private fun isMajorValidMinutes(minutes: Int): Boolean {
        return minutes > maxMinutes && minutes >= 0 && minutes < 60
    }
    
    private fun getHoursInFormat(hour: Int): String {
        return if(hour < 10) "0$hour" else "$hour"
    }
    
    private fun getMinutesInFormat(minutes: Int): String {
        return if(minutes < 10) "0$minutes" else "$minutes"
    }
    
    private fun updateResultIfMajor(a: Int, b: Int, c: Int, d: Int) {
        val hour = a*10 + b
        val minutes = c*10 + d
        
        //println("$hour - $minutes")
        if((isMajorValidHour(hour) &&  isValidMinutes(minutes))
           || (hour == maxHours && isMajorValidMinutes(minutes))
           || (hour == maxHours && minutes == maxMinutes)
          ) {
            maxHours = hour
            maxMinutes = minutes
            result = "${getHoursInFormat(hour)}:${getMinutesInFormat(minutes)}"
            //println()
        }
    }
    
    fun largestTimeFromDigits(arr: IntArray): String {
        
        
        for( i in 0 until arr.size) {
            for(j in 0 until arr.size) {
                if(i == j) {
                    continue
                }
                
                val first = arr[i]
                val second = arr[j]
                val remaining = indices.filter{it != i && it != j}
                val last = arr[remaining.first()]
                val secondLast = arr[remaining.last()]
                
                updateResultIfMajor(first, second, last, secondLast)
                updateResultIfMajor(second, first, last, secondLast)
                updateResultIfMajor(first, second, secondLast, last)
                updateResultIfMajor(second, first, secondLast, last)
            }
        }
        
        return result
    }
}