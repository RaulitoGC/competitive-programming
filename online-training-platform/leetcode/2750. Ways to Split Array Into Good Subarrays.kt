class Solution {
    
    private val mod = 1000000000 + 7
    
    fun numberOfGoodSubarraySplits(nums: IntArray): Int {
        val indices = mutableListOf<Int>()
        nums.forEachIndexed{idx, v ->
            if(v == 1) {
                indices.add(idx + 1)
            }
        }
        
        if(indices.isEmpty()){
            return 0
        }
        
        if(indices.size == 1){
            return 1
        }
        
        var result = (indices[1] - indices[0]).toLong()
        for(i in 2 until indices.size){
            val first = (result % mod)
            val second = ((indices[i] - indices[i-1]) % mod)
            val product = (first*second).toLong()
            result = product % mod
        }
        
        return result.toInt()
    }
}