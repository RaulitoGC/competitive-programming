class Solution {

    private fun minHelper(a: Int, b: Int) = kotlin.math.min(a,b)

    fun minCostClimbingStairs(cost: IntArray): Int {
        if(cost.size < 3) return minHelper(cost.first(), cost.last())

        for(idx in 2 until cost.size) {
            cost[idx] = minHelper(cost[idx - 1] + cost[idx], cost[idx - 2] + cost[idx])
        }

        return minHelper(cost[cost.size - 1], cost[cost.size - 2])
    }
}