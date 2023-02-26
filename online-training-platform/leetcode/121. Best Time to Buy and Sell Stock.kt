class Solution {
    fun maxProfit(prices: IntArray): Int {
        var sell = prices.first()
        var profit = 0

        for(idx in 1 until prices.size){
            profit = kotlin.math.max(profit, prices[idx] - sell)
            sell = kotlin.math.min(sell, prices[idx])
        }

        return profit
    }
}