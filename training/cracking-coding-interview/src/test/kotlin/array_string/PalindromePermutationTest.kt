package array_string

import Level
import Question
import org.junit.jupiter.api.Test

class PalindromePermutationTest {

    @Test
    fun testBasicImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val input = "ABCDCBA"
        val expectedResult = true
        val actualResult = problem.palindromePermutation(input)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testBasicImplementation_resultFalse() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val input = "ABCDEC"
        val expectedResult = false
        val actualResult = problem.palindromePermutation(input)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val input = "TACT COA"
        val expectedResult = true
        val actualResult = problem.palindromePermutation(input)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultFalse() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val input = "ABCDEC"
        val expectedResult = false
        val actualResult = problem.palindromePermutation(input)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testAdvanceImplementationOne_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.ADVANCE
        }

        val input = "TOAOTAA"
        val expectedResult = true
        val actualResult = problem.palindromePermutation(input)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testAdvanceImplementationTwo_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.ADVANCE
        }

        val input = "TOAOT"
        val expectedResult = true
        val actualResult = problem.palindromePermutation(input)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testAdvanceImplementationFirst_resultFalse() {
        val problem = object : Question {
            override val level: Level
                get() = Level.ADVANCE
        }

        val input = "TO A OX"
        val expectedResult = false
        val actualResult = problem.palindromePermutation(input)
        assert(actualResult == expectedResult)
    }
}