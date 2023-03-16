class Solution {
    fun increasingTriplet(nums: IntArray): Boolean {
        var first = Int.MAX_VALUE; var second = Int.MAX_VALUE

        nums.forEach{
            if(it <= first){
                first = it
            } else if(it <= second) {
                second = it
            } else {
                return true
            }
        }

        return false
    }
}