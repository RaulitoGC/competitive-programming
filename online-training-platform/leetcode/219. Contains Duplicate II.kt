class Solution {
    // Time : O(n)
    // Space: O(n)
    fun containsNearbyDuplicate(nums: IntArray, k: Int): Boolean {
        val cache = mutableMapOf<Long,Int>()

        for(i in 0 until nums.size){
            val num = nums[i].toLong()
            if(cache.contains(num)){
                val idx = cache.getOrDefault(num, -1)
                if(abs(idx - i) <= k){
                    return true
                }
            }
            cache[num] = i
        }

        return false
    }
}  