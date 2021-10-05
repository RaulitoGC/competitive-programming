 class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
      var start = 0
      var end = 0
      var res = 0
      val map = HashMap<Char, Int>()
      
      while( end < s.length){
        if(map.contains(s[end])){
          val newStart = map[s[end]]!! + 1
          start = Math.max(start, newStart)
        }
        map[s[end]] = end
        res = Math.max(res, end - start + 1)
        end += 1
      }
      
      return res
    }
}