class Solution {
    fun sortedSquares(nums: IntArray): IntArray {
        val cache = TreeMap<Int, Int>()
        nums.forEach{
            val square: Int = it * it
            cache[square] = cache.getOrDefault(square, 0) + 1
        }

        val result = IntArray(nums.size){
            0
        }

        var idx = 0
        cache.forEach{ k, v ->
            repeat(v){
                result[idx] = k
                idx += 1
            }
        }

        return result
    }
}