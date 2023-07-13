package array_string

import Level
import Question
import org.junit.jupiter.api.Test

class UniqueTest {

    @Test
    fun testBasicImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val input = "ABCDE"
        val expectedResult = true
        val actualResult = problem.isUnique(input)
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
        val actualResult = problem.isUnique(input)
        assert(actualResult == expectedResult)
    }
}