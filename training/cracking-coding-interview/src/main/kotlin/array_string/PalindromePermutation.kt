package array_string

import Question
import java.util.BitSet

/**
 * Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards. A permutation
 * is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
 */

fun Question.palindromePermutation(str: String): Boolean {
    return when (level) {
        Level.BASIC -> palindromeBasicImplementation(str)
        Level.INTERMEDIATE -> palindromeIntermediateImplementation(str)
        Level.ADVANCE -> palindromeAdvanceImplementation(str)
        else -> throw NotImplementedError("This problem does not contain ${level.name} implementation")
    }
}

/**
 * Time : O(n)
 * Space: O(n)
 */
private fun palindromeBasicImplementation(str: String) : Boolean {
    return str
        .filterNot { it == ' ' }
        .groupingBy { it }
        .eachCount()
        .filterValues { it % 2 != 0 }
        .size <= 1
}

/**
 * Time : O(n)
 * Space: O(n)
 */
private fun palindromeIntermediateImplementation(str: String) : Boolean {
    val cache = HashMap<Char, Int>()
    str.forEach {
        if(it != ' '){
            val default = cache.getOrDefault(it, 0)
            cache[it] = default + 1
        }
    }

    var oddCount = 0
    cache.forEach { (_, value) ->
        if(value % 2 != 0){
            oddCount += 1
        }
    }

    return oddCount <= 1
}

/**
 * Time : O(n)
 * Space: O(n)
 */
private fun palindromeAdvanceImplementation(str: String) : Boolean {
    val bitSet = BitSet()
    str.forEach {
        if (it != ' ') {
            val intValue = it.code
            bitSet.flip(intValue)
        }
    }
    return bitSet.cardinality() <= 1
}