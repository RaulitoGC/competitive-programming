package array_string

import Level
import Question

/**
 * Is Unique: Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional data structures?
 */

fun Question.isUnique(str: String): Boolean {
    return when (level) {
        Level.BASIC -> isUniqueBasicImplementation(str)
        Level.INTERMEDIATE -> isUniqueIntermediateImplementation(str)
        else -> throw NotImplementedError("This problem does not contain ${level.name} implementation")
    }
}

/**
 * Time: O(n*n)
 * Space: O(1)
 */
private fun isUniqueBasicImplementation(str: String): Boolean {
    for(i in str.indices){
        for(j in i + 1 until str.length) {
            if(str[i] == str[j]){
                return false
            }
        }
    }
    return true
}

/**
 * Time: O(n)
 * Space: O(n)
 */
private fun isUniqueIntermediateImplementation(str: String): Boolean {
    val cache = HashSet<Char>()
    str.forEach {
        if (cache.contains(it)) {
            return false
        }
        cache.add(it)
    }
    return true
}


