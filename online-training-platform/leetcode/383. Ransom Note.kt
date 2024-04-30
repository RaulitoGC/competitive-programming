class Solution {

    // Time O(m + n)
    // Space O(26) = O(1)
    fun canConstruct(ransomNote: String, magazine: String): Boolean {
        val ransomNoteCount = ransomNote.groupingBy{it}.eachCount()
        val magazineCount = magazine.groupingBy{it}.eachCount()

        var result = true
        ransomNoteCount.forEach{ letter, count ->
            if(magazine.contains(letter).not()){
                result = false
                return@forEach 
            }

            if(magazineCount.getOrDefault(letter, 0) < count){
                result = false
                return@forEach
            }
        }

        return result
    }
}