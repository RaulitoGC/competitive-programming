class Solution {
    fun canMakeArithmeticProgression(arr: IntArray): Boolean {
        val sorted = arr.sorted()

        
        val diff = sorted[1] - sorted[0]
        for(idx in 2 until sorted.size){
            if(sorted[idx] - sorted[idx - 1] != diff){
                return false
            }
        }

        return true
    }
}