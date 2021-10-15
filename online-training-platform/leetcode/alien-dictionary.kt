class Solution {
    fun alienOrder(words: Array<String>): String {
      val adjList = HashMap<Char, MutableList<Char>>()
      val counts = HashMap<Char, Int>()
      
      for(word in words) {
        word.forEach {
          counts[it] = 0
          adjList[it] = mutableListOf<Char>()
        }
      }
      
      for(i in 0 until words.size - 1) {
        val str1 = words[i]
        val str2 = words[i + 1]
        
        if(str1.length > str2.length && str1.startsWith(str2)){
          return ""
        }
        
        for(j in 0 until Math.min(str1.length, str2.length)) {
          if(str1[j] != str2[j]) {
            adjList[str1[j]]?.add(str2[j])
            counts[str2[j]] = counts.getOrDefault(str2[j], 0) + 1
            break
          }
        }
      }
      
      val queue = ArrayDeque<Char>()
      for( (key, value) in counts) {
        if( value == 0) {
          queue.addLast(key)
        }
      }
      
      val sb = StringBuilder()
      while(!queue.isEmpty()) {
        val c = queue.peekFirst()
        queue.removeFirst()
        sb.append(c)
        adjList[c]?.let { list ->
          list.forEach { node ->
            val newCount = counts.getOrDefault(node, 0) - 1
            counts[node] = newCount
            if(newCount == 0) {
              queue.addLast(node)
            }
          }
        }
      }
      
      if(sb.length < counts.size) {
        return ""
      }
      
      return sb.toString()
    }
}