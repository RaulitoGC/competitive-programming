package array_string

import Level
import Question
import org.junit.jupiter.api.Test

class URLifyTest {

    @Test
    fun testBasicImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val input = "AB CDE  "
        val length = 6
        val expectedResult = "AB%20CDE"
        val actualResult = problem.urLify(input, length)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val input = "A BC D E    "
        val length = 8
        val expectedResult = "A%20BC%20D%20E"
        val actualResult = problem.urLify(input, length)
        assert(actualResult == expectedResult)
    }
}
