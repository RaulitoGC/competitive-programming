class Solution {
    fun fib(n: Int): Int {
        if( n == 0) return 0
        if( n == 1) return 1

        var first = 0; var second = 1
        repeat(n) {
            first = second.also{
                second = first + second
            }
            println(first)
            println(second)
            println()
        }
        return first
    }
}