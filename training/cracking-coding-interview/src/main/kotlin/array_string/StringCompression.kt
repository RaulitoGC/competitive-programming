package array_string

import Question

fun Question.stringCompression(str: String): String {
    return when (level) {
        Level.BASIC -> stringCompressionBasicImplementation(str)
        Level.INTERMEDIATE -> stringCompressionIntermediateImplementation(str)
        else -> throw NotImplementedError("This problem does not contain ${level.name} implementation")
    }
}

/**
 * Time: O(n)
 * Space: O(n)
 */
private fun stringCompressionIntermediateImplementation(str: String): String {
    if(str.isEmpty()){
        return str
    }

    var letter = str[0]
    var count = 1
    val sb = StringBuilder()
    for( i in 1 until str.length){
        if(str[i] == letter){
            count += 1
        } else {
            sb.append(count)
            sb.append(letter)
            letter = str[i]
        }
    }

    sb.append(count)
    sb.append(letter)

    val result = sb.toString()
    return if(result.length < str.length) result else str
}

/**
 * Time: O(n)
 * Space: O(n)
 */
private fun stringCompressionBasicImplementation(str: String): String {
    val cacheCount = str.groupingBy { it }.eachCount()
    val sb = StringBuilder()
    str.toSet().forEach { c ->
        cacheCount[c]?.let{ count ->
            sb.append(count)
            sb.append(c)
        }
    }

    val result = sb.toString()
    return if(result.length < str.length) result else str
}
