package array_string

import Level
import Question
import org.junit.jupiter.api.Test

class StringCompressionTest {

    @Test
    fun testBasicImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val input = "aabbccddeeee"
        val expectedResult = "2a2b2c2d4e"
        val actualResult = problem.stringCompression(input)
        println(actualResult)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val input = "abcdefg"
        val actualResult = problem.stringCompression(input)
        assert(actualResult == input)
    }
}
