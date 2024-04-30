package array_string

import Question

/**
 * One Away: There are three types of edits that can be performed on strings: insert a character,
 * remove a character, or replace a character. Given two strings, write a function to check if they are
 * one edit (or zero edits) away.
 */

fun Question.oneAway(str1: String, str2: String): Boolean {
    return when (level) {
        Level.BASIC -> oneAwayBasicImplementation(str1, str2)
        Level.INTERMEDIATE -> oneAwayIntermediateImplementation(str1, str2)
        else -> throw NotImplementedError("This problem does not contain ${level.name} implementation")
    }
}

/**
 * Time: O(n*m)
 * Space: O(1)
 */
private fun oneAwayBasicImplementation(str1: String, str2: String): Boolean {
    val lessInput = if(str1.length < str2.length) str1 else str2
    val majorInput = if(str1.length < str2.length) str2 else str1

    var changes = 0
    for (i in lessInput.indices) {
        val current = lessInput[i]
        var found = false
        for (j in majorInput.indices) {
            if (current == majorInput[j]) {
                found = true
            }
        }
        if (!found) {
            changes += 1
        }
    }

    return changes <= 1
}

/**
 * Time: O(n + m)
 * Space: O(n)
 */
private fun oneAwayIntermediateImplementation(str1: String, str2: String): Boolean {
    val lessInput = if(str1.length < str2.length) str1 else str2
    val majorInput = if(str1.length < str2.length) str2 else str1

    val cache = HashMap<Char, Int>()
    for(i in lessInput.indices){
        val current = cache.getOrDefault(lessInput[i], 0)
        cache[lessInput[i]] = current + 1
    }

    var notFound = 0
    majorInput.forEach {
        val current = cache.getOrDefault(it, 0)
        cache[it] = current - 1
        if(current - 1 < 0) {
            notFound += 1
        }
    }

    return notFound <= 1
}