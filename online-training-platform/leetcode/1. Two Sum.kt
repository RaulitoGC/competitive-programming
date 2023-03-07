class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val cache = HashMap<Int, Int>()
        nums.forEachIndexed{ idx, v ->
            if(cache.contains(target - v)){
                return intArrayOf(idx, cache[target-v]!!)
            }

            cache[v] = idx
        }

        return intArrayOf()
    }
}