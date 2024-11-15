class Solution {
    
    private fun isGood(word: String, count: Map<Char, Int>): Int{
        val charsCount = count.toMutableMap()
        word.forEach { c ->
            if(charsCount.contains(c)){
                val currentValue = charsCount.getOrDefault(c, 0)
                if(currentValue < 1) {
                    return 0
                }
                charsCount[c] = currentValue - 1
            } else {
                return 0
            }
        }
        
        return word.length
    }
    
    /*
    *   words.length = n
    *   chars.length = m
    *   word.length = k
    *   Time: O(m + n * k)
    *   Space: O(m)
     */ 
    fun countCharacters(words: Array<String>, chars: String): Int {
        // O(m)
        val count = chars.groupingBy{it}.eachCount()
        var result = 0
        // O(n) x O(k)
        words.forEach{ word ->
            result += isGood(word, count)
        }
        
        return result
        
    }
}