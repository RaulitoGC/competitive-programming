class Solution {  
    
    fun suggestedProducts(products: Array<String>, searchWord: String): List<List<String>> {
      
      val n = searchWord.length
      val res = mutableListOf<List<String>>()
      for(i in 1 until n + 1){
        val search = searchWord.substring(0, i)
        println(search)
        val array = products.filter{
          it.startsWith(search)
        }
        
        println(array)
        res.add(
          if(array.size > 3) array.sorted().take(3) else array.sorted()        
        )
      }
      
      return res
    }
}