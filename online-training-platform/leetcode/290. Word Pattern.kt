class Solution {
    fun wordPattern(pattern: String, s: String): Boolean {
        val words = s.split(" ")
        val wordToLetter = HashMap<String, Char>()
        val letterToWord = HashMap<Char, String>()
        
        if(words.size != pattern.length) {
            return false
        }
        
        val size = words.size
        words.forEachIndexed { idx, word ->
            if(wordToLetter.contains(word)){
                if(wordToLetter.getOrDefault(word, " ") != pattern[idx]){
                    return false
                }
            }
            
            if(letterToWord.contains(pattern[idx])){
                if(letterToWord.getOrDefault(pattern[idx], ' ') != word) {
                    return false
                }
            }
            
            wordToLetter[word] = pattern[idx]
            letterToWord[pattern[idx]] = word
        }
        
        return true
    }
}