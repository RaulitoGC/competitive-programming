class Solution {

    /*
        n is the number of elements in arr1.
        m is the number of elements in arr2.
        Time Complexity: O(n + m)
        Space Complexity: O(n)
    */
    fun relativeSortArray(arr1: IntArray, arr2: IntArray): IntArray {
        val count = TreeMap<Int, Int>()
        
        arr1.forEach {
            count[it] = count.getOrDefault(it, 0) + 1
        }
        
        val result = mutableListOf<Int>()
        
        arr2.forEach{ number ->
            val limit = count.getOrDefault(number, 0)
            repeat(limit) {
                result.add(number)
            }
            count.remove(number)
        }
        
        count.forEach{ k, v ->
            repeat(v){
                result.add(k)
            }
        }
        
        
        return result.toIntArray()
    }
}