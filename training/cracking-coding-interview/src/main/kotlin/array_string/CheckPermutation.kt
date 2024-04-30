package array_string

import Question

/**
 * Check Permutation: Given two strings, write a method to decide if one is a permutation of the
 * other.
 */

fun Question.checkPermutation(str1: String, str2: String): Boolean {
    return when (level) {
        Level.BASIC -> checkPermutationBasicImplementation(str1, str2)
        Level.INTERMEDIATE -> checkPermutationIntermediateImplementation(str1, str2)
        Level.ADVANCE -> checkPermutationAdvanceImplementation(str1, str2)
        else -> throw NotImplementedError("This problem does not contain ${level.name} implementation")
    }
}

/**
 * Time: O(n*m)
 * Space: O(1)
 */
private fun checkPermutationBasicImplementation(str1: String, str2: String): Boolean {
    var found: Boolean
    for (i in str1.indices) {
        val current = str1[i]
        found = false
        for (j in str2.indices) {
            if (str2[j] == current) {
                found = true
                break
            }
        }
        if (found.not()) {
            return false
        }
    }
    return true
}

/**
 * Time: O(nLogn + mLogm)
 * Space: O(1)
 */
private fun checkPermutationIntermediateImplementation(str1: String, str2: String): Boolean {
    return str1.toCharArray().sorted() == str2.toCharArray().sorted()
}

/**
 * Time: O(n)
 * Space: O(n)
 */
private fun checkPermutationAdvanceImplementation(str1: String, str2: String): Boolean {
    val cache = HashSet<Char>()
    str1.forEach { s1 ->
        cache.add(s1)
    }

    str2.forEach { s2 ->
        if (cache.contains(s2).not()) {
            return false
        }
    }

    return true
}