class Solution {
    fun characterReplacement(s: String, k: Int): Int {
        val size = s.length
        val frequency = IntArray(26){0}
        var maxFrequency = 0
        var start = 0
        var result = 0

        for(end in 0 until size) {
            frequency[s[end] - 'A'] += 1
            maxFrequency = kotlin.math.max(maxFrequency, frequency[s[end] - 'A'])
            while(end - start + 1 - maxFrequency > k){
                frequency[s[start] - 'A'] -= 1
                start += 1
            }

            result = kotlin.math.max(result, end - start + 1)
        }
        return result
    }
}