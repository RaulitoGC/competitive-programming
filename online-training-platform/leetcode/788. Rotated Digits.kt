class Solution {
    
    private val mapper = mapOf<Int, Int>(
        2 to 5,
        5 to 2,
        6 to 9,
        9 to 6,
        0 to 0,
        1 to 1,
        8 to 8
    )
    
    private fun isValid(n: Int): Boolean {
        var number = n
        var decimal = 1
        var finalNumber = 0
        while(number != 0) {
            val remainder = number % 10
            if(mapper.contains(remainder)) {
                val rotated = mapper.getOrDefault(remainder, 0)
                finalNumber += (rotated * decimal)
                decimal = decimal * 10
            }else {
                return false
            }
            number = (number / 10)
        }
        
        //println("$finalNumber - $n")
        return finalNumber != n
    }
    
    fun rotatedDigits(n: Int): Int {
        var result = 0
        repeat(n){
            result += if(isValid(it + 1)) 1 else 0
        }
        
        return result
    }
}