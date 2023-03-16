class Solution {
    fun wordPattern(pattern: String, s: String): Boolean {
        val letterToWord = HashMap<Char, String>()
        val wordToLetter = HashMap<String, Char>()

        val words = s.split(" ")
        if(pattern.length != words.size) {
            return false
        }

        words.forEachIndexed{ idx, word ->
            if(letterToWord.contains(pattern[idx])){
                val current = letterToWord.getOrDefault(pattern[idx], "")
                if(current != word) return false
            }

            if(wordToLetter.contains(word)){
                val current = wordToLetter.getOrDefault(word, ' ')
                if(current != pattern[idx]) return false
            }

            letterToWord[pattern[idx]] = word
            wordToLetter[word] = pattern[idx]
        }

        return true
    }
}