class Solution {
    
    private val cache = HashMap<String, Int>()
    
    private fun getKey(values: IntArray): String {
        val first = values.first()
        val last = values.last()
        return "${min(first,last)}-${max(first,last)}"
    }
    
    fun numEquivDominoPairs(dominoes: Array<IntArray>): Int {
        
        dominoes.forEach{ 
            val key = getKey(it)
            cache[key] = cache.getOrDefault(key, 0) + 1
        }
        
        var result = 0
        
        cache.forEach{ _, v ->
            result += ((v * ( v - 1)) / 2)
        }
        
        
        return result
    }
}