class Solution {
  fun longestPalindrome(s: String): Int {
      val count = s.groupingBy{it}.eachCount()

      var size = 0
      var isThereEven = false
      count.forEach{ k, v ->
          if(v % 2 != 0) {
              size += v - 1
              isThereEven = true
          } else {
              size += v
          }
      }

      if(isThereEven) {
          size += 1
      }

      return size
  }
}