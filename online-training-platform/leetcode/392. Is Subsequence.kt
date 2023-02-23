class Solution {
    fun isSubsequence(s: String, t: String): Boolean {
        if(s.length > t.length){
            return false
        }

        var sIdx = 0; var tIdx = 0

        while(sIdx < s.length && tIdx < t.length){
            if(s[sIdx] == t[tIdx]) {
                sIdx += 1  
            } 
            tIdx += 1
        }

        return sIdx == s.length
    }
}