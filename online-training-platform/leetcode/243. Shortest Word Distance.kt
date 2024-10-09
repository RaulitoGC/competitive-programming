class Solution {
    fun shortestDistance(wordsDict: Array<String>, word1: String, word2: String): Int {
        val distancesWord1 = mutableListOf<Int>()
        val distancesWord2 = mutableListOf<Int>()
        
        wordsDict.forEachIndexed{ idx, word ->
            if(word == word1){
                distancesWord1.add(idx)
            } else if (word == word2) {
                distancesWord2.add(idx)
            }
        }
        
        var minComparison = Int.MAX_VALUE
        var idx1 = 0; var idx2 = 0
        
        while(idx1 < distancesWord1.size && idx2 < distancesWord2.size) {
            var first = distancesWord1[idx1]
            var second = distancesWord2[idx2]
            
            if(first < second){
                minComparison = min(second - first, minComparison)
                idx1 += 1
            } else {
                minComparison = min(first - second, minComparison)
                idx2 += 1
            }
        }
        
        return minComparison
    }
}