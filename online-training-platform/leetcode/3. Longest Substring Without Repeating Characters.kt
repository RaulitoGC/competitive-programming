class Solution {
    
    private val cache = HashMap<Char, Int>()

    fun lengthOfLongestSubstring(s: String): Int {
        var result = 0
        var idx = 0

        while(idx < s.length){

            while(idx < s.length && cache.contains(s[idx]).not()){
                cache[s[idx]] = idx
                idx += 1
            }

            result = max(result, cache.size)
            if(idx < s.length){
                idx = cache.getOrDefault(s[idx], idx - 1) + 1
            }
            cache.clear()
        }

        return result
    }
}