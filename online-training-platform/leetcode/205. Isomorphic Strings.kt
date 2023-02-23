class Solution {
    fun isIsomorphic(s: String, t: String): Boolean {
        
        val sMap = HashMap<Char, Char>()
        val tMap = HashMap<Char, Char>()
        val size = s.length

        for(i in 0 until size) {
            if(sMap.contains(s[i]).not()){
                sMap[s[i]] = t[i]

                if(tMap.contains(t[i]).not()) {
                    tMap[t[i]] = s[i]
                } else if(tMap[t[i]] != s[i]) {
                    return false
                }

            } else if(sMap[s[i]] != t[i]){
                return false
            }
        }
        
        return true
    }
}