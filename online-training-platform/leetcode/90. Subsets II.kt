class Solution {

    

    fun subsetsWithDup(nums: IntArray): List<List<Int>> {
        
        val result = HashSet<List<Int>>()
        fun helper(nums: IntArray, idx: Int, current: List<Int>) {
            
            val sort = current.sorted()
            if(result.contains(sort).not()){
                result.add(sort)
            }
            
            for(i in idx until nums.size){
                helper(nums, i + 1, current + listOf(nums[i]))
            }
        }

        helper(nums, 0, listOf<Int>())
        return result.toList()
    }
}