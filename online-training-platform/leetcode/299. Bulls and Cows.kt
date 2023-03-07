class Solution {
    fun getHint(secret: String, guess: String): String {
        
        val guessCount : MutableMap<Char, Int> = guess.groupingBy{it}.eachCount().toMutableMap()
        val size = secret.length
        var cows = 0; var bulls = 0
        for(idx in 0 until size){
            val secretValue = secret[idx]
            if(secretValue == guess[idx]){
                cows += 1
                val current = guessCount.getOrDefault(secretValue, 0)
                guessCount[secretValue] = current - 1
            }
        }

        for(idx in 0 until size) {
            val secretValue = secret[idx]
            if(secretValue != guess[idx]) {
                val current = guessCount.getOrDefault(secretValue, 0)
                if(guessCount.contains(secretValue) && current > 0) {
                    guessCount[secretValue] = current - 1
                    bulls += 1
                }
            }
        }


        return "${cows}A${bulls}B"
    }
}