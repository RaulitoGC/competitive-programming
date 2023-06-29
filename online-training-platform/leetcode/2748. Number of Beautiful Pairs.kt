class Solution {
    
    private fun gcd(x: Int, y: Int): Int {
        return if(y == 0) x else gcd(y, x % y)
    }
    
    fun countBeautifulPairs(nums: IntArray): Int {
        var count = 0
        for(i in 0 until nums.size) {
            for(j in i + 1 until nums.size) {
                var x = nums[i]
                while(x >= 10) {
                    x = x / 10
                }
                val y = if(nums[j] >= 10) nums[j] % 10 else nums[j]
                if(gcd(x, y) == 1){
                    count += 1
                }
            }
        }
        return count
    }
}