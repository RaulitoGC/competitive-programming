class Solution {

    private fun getMaxWithExclussion(nums: IntArray, exclussions: Set<Int>): Int {
        var maxValue = Int.MIN_VALUE
        nums.forEach{
            if(exclussions.contains(it)) {
                return@forEach
            }
            maxValue = max(maxValue, it)
        }
        return maxValue
    }

    private fun isThirdMaxExist(nums: IntArray): Boolean {
        return nums.distinct().size >= 3
    }

    fun thirdMax(nums: IntArray): Int {
        val size = nums.size
        var result = Int.MIN_VALUE
        val exclussions = hashSetOf<Int>()

        if(isThirdMaxExist(nums)) {
            repeat(3){
                val maxValue = getMaxWithExclussion(nums, exclussions)
                exclussions.add(maxValue)
                result = maxValue
            }
            
        } else {
            repeat(size){
                val maxValue = getMaxWithExclussion(nums, exclussions)
                exclussions.add(maxValue)
                result = max(result, maxValue)
            }
        }

        return result
    }
}