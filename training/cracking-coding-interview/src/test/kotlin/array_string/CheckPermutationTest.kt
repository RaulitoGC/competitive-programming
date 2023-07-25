package array_string

import Level
import Question
import org.junit.jupiter.api.Test

class CheckPermutationTest {

    @Test
    fun testBasicImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val str1 = "ABCDE"; val str2 = "ADECB"
        val expectedResult = true
        val actualResult = problem.checkPermutation(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testBasicImplementation_resultFalse() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val str1 = "ABCDE"; val str2 = "AXECB"
        val expectedResult = false
        val actualResult = problem.checkPermutation(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val str1 = "ABCDE"; val str2 = "ADECB"
        val expectedResult = true
        val actualResult = problem.checkPermutation(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultFalse() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val str1 = "ABCDE"; val str2 = "AXECB"
        val expectedResult = false
        val actualResult = problem.checkPermutation(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testAdvanceImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.ADVANCE
        }

        val str1 = "ABCDE"; val str2 = "ADECB"
        val expectedResult = true
        val actualResult = problem.checkPermutation(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testAdvanceImplementation_resultFalse() {
        val problem = object : Question {
            override val level: Level
                get() = Level.ADVANCE
        }

        val str1 = "ABCDE"; val str2 = "AXECB"
        val expectedResult = false
        val actualResult = problem.checkPermutation(str1, str2)
        assert(actualResult == expectedResult)
    }
}
