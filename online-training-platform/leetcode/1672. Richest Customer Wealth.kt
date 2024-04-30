class Solution {

    // Time Complexity : O(MxN)
    // Space complecity: O(1)
    fun maximumWealth(accounts: Array<IntArray>): Int {
        
        val customers = accounts.size
        val banks = accounts[0].size

        var maxAmount = 0
        for(customer in 0 until customers){
            var currentAmount = 0
            for(bank in 0 until banks){
                currentAmount += accounts[customer][bank]
            }
            maxAmount = max(currentAmount, maxAmount)
        }

        return maxAmount
    }
}