class Solution {

    fun findAnagrams(s: String, p: String): List<Int> {
        val pSize = p.length
        val sSize = s.length
        if(pSize > sSize){
            return emptyList<Int>()
        }

        val sCache = HashMap<Char, Int>()
        val pCache = HashMap<Char, Int>()

        p.forEach{
            val current = pCache.getOrDefault(it, 0)
            pCache[it] = current + 1
        }

        for(idx in 0 until pSize) {
            val current = sCache.getOrDefault(s[idx], 0)
            sCache[s[idx]] = current + 1
        }

        var result = if(pCache == sCache) mutableListOf(0) else mutableListOf()
        
        for(idx in 1 until sSize - pSize + 1) {
            val prev = sCache.getOrDefault(s[idx - 1], 0)
            if(prev > 1){
                sCache[s[idx - 1]] = prev - 1    
            } else {
                sCache.remove(s[idx - 1])
            }
            
            val next = sCache.getOrDefault(s[idx + pSize - 1], 0)
            sCache[s[idx + pSize - 1]] = next + 1

            println("$sCache -- $pCache")
            if(sCache == pCache){
                result.add(idx)
            }
        }
        
        return result
    }
}