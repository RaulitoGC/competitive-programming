class Solution {
    fun arraySign(nums: IntArray): Int {
        var sign = 1
        nums.forEach{
            if(it  == 0) {
                return 0
            }
            sign *= if( it < 0) -1 else 1
        }
        return sign
    }
}