class Solution {
    
    private fun gcd(a: Int, b: Int): Int {
        if(b == 0){
            return a
        }
        
        return gcd(b, a % b)
    }
    
    private fun getStringGcd(str1: String, str2: String, size: Int): String {
        val size1 = str1.length
        val size2 = str2.length
        
        val t = str1.substring(0, size)
        //println(t)
        
        val sb1 = StringBuilder()
        repeat(size1 / size) {
            sb1.append(t)
        }
        
        if(sb1.toString() != str1){
            return ""
        }
        
        val sb2 = StringBuilder()
        repeat(size2 / size){
            sb2.append(t)
        }
        
        if(sb2.toString() != str2){
            return ""
        }
        
        return t
    }
    
    // l1: length of str1
    // l2: length of str2
    // Time: O(log(min(l1, l2)) + log(min(l1, l2)) * (l1 + l2))
    // Space: O(l1 + l2)
    fun gcdOfStrings(str1: String, str2: String): String {
        val size1 = str1.length
        val size2 = str2.length
        
        val gcd = gcd(size1, size2)
        
        for(i in gcd downTo 1) {
            if( gcd % i == 0){
                val result = getStringGcd(str1, str2, i) 
                if(result.isNotEmpty()){
                    return result
                }
            }
        }
        
        return ""
    }
}