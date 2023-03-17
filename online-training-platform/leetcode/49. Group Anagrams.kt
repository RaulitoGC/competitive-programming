class Solution {

    fun String.alphabetized() = String(toCharArray().apply { sort() })

    fun groupAnagrams(strs: Array<String>): List<List<String>> {
        val cache = HashMap<String, MutableList<String>>()
        strs.forEach{
            val sorted = it.alphabetized()
            if(cache.contains(sorted).not()){
                cache[sorted] = mutableListOf<String>()
            }

            cache[sorted]?.add(it)
        }

        val result = mutableListOf<List<String>>()

        for((k,v) in cache) {
            result.add(v)
        }

        return result
    }
}