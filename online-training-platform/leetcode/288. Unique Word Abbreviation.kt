class ValidWordAbbr(dictionary: Array<String>) {

    private val abbreviations = HashMap<String,Int>()
    private val words = HashSet<String>()

    init {
        dictionary.forEach{
            val abbreviation = getAbbreviation(it)
            abbreviations[abbreviation] = abbreviations.getOrDefault(
                abbreviation, 0
            ) + if(words.contains(it)) 0 else 1
            words.add(it)
        }
    }

    private fun getAbbreviation(word: String): String {
        if(word.length <= 2){
            return word
        }
        val firstLetter = word.first()
        val lastLetter = word.last()
        val builder = StringBuilder()
        builder.append(firstLetter)
        builder.append(word.length - 2)
        builder.append(lastLetter)

        return builder.toString()
    }

    fun isUnique(word: String): Boolean {
        val abbreviation = getAbbreviation(word)

        if(abbreviations.contains(abbreviation)){
            return words.contains(word) && abbreviations.getOrDefault(abbreviation, 0) == 1
        }

        return true
    }

}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * var obj = ValidWordAbbr(dictionary)
 * var param_1 = obj.isUnique(word)
 */