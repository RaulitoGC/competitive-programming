class Solution {
    fun buddyStrings(s: String, goal: String): Boolean {
        if(s.length != goal.length) {
            return false
        }
        
        if(s == goal) {
            val atLeastTwoEquals = s.groupingBy{ it}.eachCount().filter{
                it.value > 1
            }
            
            return atLeastTwoEquals.isNotEmpty()
        }
        
        val size = s.length
        var swapPair: Pair<Char,Char>? = null
        var atLeastOneSwap = false
        repeat(size){
            val firstLetter = s[it]
            val secondLetter = goal[it]
            
            if(firstLetter != secondLetter) {
                
                if(swapPair == null) {
                    swapPair = Pair(firstLetter, secondLetter)    
                } else {
                    if(swapPair?.first != secondLetter || swapPair?.second != firstLetter){
                        return false
                    }
                    atLeastOneSwap = !atLeastOneSwap
                }
            }
        }
        
        if(atLeastOneSwap.not()) {
            return false
        }
        
        return true
    }
}