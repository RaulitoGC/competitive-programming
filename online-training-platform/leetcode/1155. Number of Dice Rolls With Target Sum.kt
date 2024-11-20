class Solution {
    
    private var target = 0
    private var k = 0
    private var dices = 0
    private val MOD = 1000000000 + 7
    private lateinit var cache: Array<IntArray>
    
    private fun rollDice(sum: Int, dice: Int) : Int {
        //println("sum -> $sum - dice -> $dice")
        if(dice > dices || sum > target){
            return 0
        }
        
        if(cache[sum][dice] != -1){
            return cache[sum][dice] ?: 0
        }
        
        if(sum == target && dice == dices){
            return 1
        }
        
        var result = 0
        repeat(k){
            val currentResult = rollDice(sum + it + 1, dice + 1)
            result = ((result % MOD) + (currentResult % MOD)) % MOD
        }
        
        cache[sum][dice] = result
        return result
    }
    
    fun numRollsToTarget(n: Int, k: Int, target: Int): Int {
        this.target = target
        this.k = k
        this.dices = n
        
        this.cache = Array<IntArray>(target + 1){
            IntArray(n + 1){
                -1
            }
        }
        
        return rollDice(0, 0)
    }
}