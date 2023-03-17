class Solution {
    fun partitionLabels(s: String): List<Int> {
        val cache = HashMap<Char, Pair<Int, Int>>()

        s.forEachIndexed{ idx, c ->
            if(cache.contains(c)){
                val current = cache.getOrDefault(c, Pair(Int.MAX_VALUE, Int.MIN_VALUE))
                val first = kotlin.math.min(current.first, idx)
                val second = kotlin.math.max(current.second, idx)
                cache[c] = Pair(first, second)
            } else {
                cache[c] = Pair(idx, idx)
            }
        }

        val result = mutableListOf<Int>()
        var maxSize = 0
        var idx = 0
        while( idx < s.length){
            val letter = cache.getOrDefault(s[idx], Pair(Int.MAX_VALUE, Int.MIN_VALUE))
            val start = letter.first
            var end = letter.second
            var startIdx = start + 1

            while(startIdx < end) {
                val anotherEnd = cache.getOrDefault(s[startIdx], Pair(Int.MAX_VALUE, Int.MIN_VALUE)).second
                if(anotherEnd > end){
                    end = anotherEnd
                }
                startIdx += 1
            }

            result.add(end - start + 1)
            idx = end + 1
        }

        return result
    }
}