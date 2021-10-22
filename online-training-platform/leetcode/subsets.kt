class Solution {
    
    val visited = HashSet<Int>()
    val solutions = mutableListOf<List<Int>>()
    private lateinit var nums : IntArray
    
    
    fun isValidNumber(number: Int) : Boolean {
        visited.forEach { n ->
            if(n > number) {
                return false
            }
        }
        
        return true
    }
    
    // visited = []
    // solutions = [], [1] , [1,2] , [1,2,3], [1,3], [2], [2, 3], [3], 
    // list = []
    fun backtrack(size : Int, list: MutableList<Int>) {
        if(size == list.size){
            solutions.add(list.toList())
        }
        
        nums.forEach { number ->
            if(!visited.contains(number) && isValidNumber(number)) {
                list.add(number)
                visited.add(number)
                backtrack(size + 1, list)
                list.removeAt(list.size - 1)
                visited.remove(number)
            }
        }
    }
    
    fun subsets(nums: IntArray): List<List<Int>> {
        this.nums = nums
        backtrack(0, mutableListOf<Int>())
        return solutions
    }
}