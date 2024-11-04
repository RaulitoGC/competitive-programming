class Solution {
    
    private val MONTHS_TO_DAY = listOf<Int>(31,28,31,30,31,30,31,31,30,31,30,31)
    
    private fun isLeap(year: Int): Boolean {
        return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0))
    }
    
    private fun getDays(date: String): Int {
        var result = 0
        
        val components = date.split("-")
        val year = components[0].toInt()
        val month = components[1].toInt()
        val day = components[2].toInt()
        
        var initYear = 1971
        while(initYear < year ){
            result += 365
            if(isLeap(initYear)){
                result += 1
            }
            initYear += 1
        }
        
        var initMonth = 0
        val endMonth = month - 1
        while(initMonth < endMonth){
            result += MONTHS_TO_DAY[initMonth]
            if(initMonth == 1 && isLeap(year)){
                result += 1
            }
            initMonth += 1
        }
        
        result += day
        
        return result
    }
    
    fun daysBetweenDates(date1: String, date2: String): Int {
        
        val days1 = getDays(date1)
        val days2 = getDays(date2)
        
        return abs(days1 - days2)
    }
}