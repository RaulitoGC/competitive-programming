class Solution {
    fun dietPlanPerformance(calories: IntArray, k: Int, lower: Int, upper: Int): Int {
        
        val size = calories.size
        val acum = IntArray(size + 1){
            0
        }
        
        var idx = 0
        while(idx < size){
            acum[idx + 1] = calories[idx] + acum[idx]
            idx += 1
        }
        
        var start = 0; var end = k
        
        var points = 0
        var result = 0
        
        while(end <= size) {
            points = acum[end] - acum[start]
            val valueToAdd = (if(points > upper) 1 else if( points < lower) -1 else 0)
            result += valueToAdd
            end += 1
            start += 1
        }
        
        return result
    }
}