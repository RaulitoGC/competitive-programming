package array_string

import Level
import Question

/**
 * URLify: Write a method to replace all spaces in a string with '%20: You may assume that the string
 * has sufficient space at the end to hold the additional characters, and that you are given the "true"
 * length of the string. (Note: If implementing in Java, please use a character array so that you can
 * perform this operation in place.)
 */

fun Question.urLify(str: String, length: Int): String {
    return when (level) {
        Level.BASIC -> urLifyBasicImplementation(str, length)
        Level.INTERMEDIATE -> urLifyIntermediateImplementation(str, length)
        else -> throw NotImplementedError("This problem does not contain ${level.name} implementation")
    }
}

/**
 * Time: O(L)
 * Space: O(L)
 */
private fun urLifyBasicImplementation(str: String, length: Int) : String {
    return str.take(length).replace(" ", "%20")
}


/**
 * Time: O(L)
 * Space: O(L)
 */
private fun urLifyIntermediateImplementation(str: String, length: Int) : String {
    val sb = StringBuilder()
    for(i in 0 until length){
        val current = str[i]
        if(current == ' '){
            sb.append("%20")
            continue
        }
        sb.append(current)
    }
    return sb.toString()
}
