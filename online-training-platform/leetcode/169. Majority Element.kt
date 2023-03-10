class Solution {
    fun majorityElement(nums: IntArray): Int {
        val limit = nums.size / 2
        var counter = 1

        val sorted = nums.sorted()
        var num = sorted.first()
        for(idx in 1 until sorted.size) {
            if(sorted[idx] == num){
                counter += 1
            } else {
                num = sorted[idx]
                counter = 1
            }

            if(counter > limit){
                return sorted[idx]
            }
        }

        return num
    }
}