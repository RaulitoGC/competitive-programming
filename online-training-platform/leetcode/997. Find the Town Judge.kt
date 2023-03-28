class Solution {
    fun findJudge(n: Int, trust: Array<IntArray>): Int {
        val cache = HashMap<Int, Int>()
        repeat(n){ idx ->
            cache[idx + 1] = 0
        }

        trust.forEach{
            val key = it.first()
            val value = it.last()
            
            if(cache.contains(key)){
                cache.remove(key)
            }

            if(cache.contains(value)){
                cache[value] = cache.getOrDefault(value, 0) + 1
            }
        }
        
        return if(cache.isNotEmpty() && cache.values.first() == n-1) cache.keys.first() else -1
    }
}