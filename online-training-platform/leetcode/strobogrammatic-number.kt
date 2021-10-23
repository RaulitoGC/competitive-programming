class Solution {
    fun findStrobogrammatic(n: Int): List<String> {
      return backtrack(n, n)  
    }
    
    fun backtrack(n: Int, original: Int): List<String>{
      if(n == 0) {
        return listOf<String>("")
      }
      
      if(n == 1) {
        return listOf<String>("0", "1", "8")
      }
      
      val prevs = backtrack(n - 2, original)
      val results = mutableListOf<String>()
      prevs.forEach{
        if(n != original) {
          results.add("0${it}0")
        }
        results.add("1${it}1")
        results.add("8${it}8")
        results.add("6${it}9")
        results.add("9${it}6")
      }
      return results
    }
}