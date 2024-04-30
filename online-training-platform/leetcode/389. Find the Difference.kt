class Solution {
    /**
        N = size s / M = N + 1
        Time: O(N + M) = O(N + N + 1) = O(2N + 1) = O(N)
        Space: O(1)
        
     */
    fun findTheDifference(s: String, t: String): Char {
        if(s.length == 0){
            return t[0]
        }

        var result = t[0].toInt()
        for(i in 0 until s.length){
            result = result xor (s[i].toInt())
        }

        for(i in 1 until t.length){
            result = result xor (t[i].toInt())
        }
        
        return result.toChar()
    }
}