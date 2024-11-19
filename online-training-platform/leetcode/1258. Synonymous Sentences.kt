class Solution {

    /*
        n is the number of synonym pairs.
        m is the number of words in the input text.
        k is the average number of synonyms per word.
        result size = r
        Time Complexity: O(n + m^2 * k^(m+1))
        Space Complexity: O(n + k^m)  
    */
    fun generateSentences(synonyms: List<List<String>>, text: String): List<String> {
        
        val cache = HashMap<String, List<String>>()
        synonyms.forEach { list ->
            val first = list.first()
            val last = list.last()
            
            cache[first] = cache.getOrDefault(first, listOf<String>()) + listOf(last)
            cache[last] = cache.getOrDefault(last, listOf<String>()) + listOf(first)
        }
        
        println(cache)
        
        
        val result = mutableSetOf<String>()
        val queue = ArrayDeque<String>()
        queue.addLast(text)
        
        
        while(queue.isNotEmpty()) {
            val current = queue.first()
            queue.removeFirst()
            result.add(current)
            
            val words = current.split(" ").toMutableList()
            words.forEachIndexed{ idx, word ->
                cache.getOrDefault(word, listOf<String>()).forEach { synonym ->
                    words[idx] = synonym
                    val currentText = words.joinToString(" ")
                    if(result.contains(currentText).not()) {
                        // println(currentText)
                        queue.addLast(currentText)    
                    }
                }
            }
        }
        
        
        return result.sorted()
    }
}