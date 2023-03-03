class Solution {
    fun climbStairs(n: Int): Int {
        if( n == 1) return 1
        if( n == 2) return 2

        var first = 0; var second = 1
        repeat(n) {
            first = second.also {
                second = first + second
            }
        }

        return second
    }
}