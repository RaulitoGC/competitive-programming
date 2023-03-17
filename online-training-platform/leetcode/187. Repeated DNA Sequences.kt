class Solution {
    fun findRepeatedDnaSequences(s: String): List<String> {
        var start = 0; var end = s.length
        val result = mutableListOf<String>()
        val cache = HashMap<String, Int>()
        while( start < end - 9){
            val subString = s.substring(start, start + 10)
            //println(subString)
            cache[subString] = cache.getOrDefault(subString, 0) + 1
            start += 1
        }

        for((k, v) in cache){
            if(v > 1){
                result.add(k)
            }
        }

        return result
    }
}