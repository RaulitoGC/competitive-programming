package array_string

import Level
import Question
import org.junit.jupiter.api.Test

class RotateMatrixTest {

    @Test
    fun testBasicImplementation_resultOneMatch() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val input = arrayOf(
            intArrayOf(1,2),
            intArrayOf(3,4)
        )
        val expectedResult = arrayOf(
            intArrayOf(2,4),
            intArrayOf(1,3)
        )
        val actualResult = problem.rotateMatrix(input)
        assert(actualResult.contentDeepEquals(expectedResult))
    }


    @Test
    fun testBasicImplementation_resultTwoMatch() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val input = arrayOf(
            intArrayOf(1,2,3),
            intArrayOf(4,5,6),
            intArrayOf(7,8,9)
        )
        val expectedResult = arrayOf(
            intArrayOf(3,6,9),
            intArrayOf(2,5,8),
            intArrayOf(1,4,7)
        )
        val actualResult = problem.rotateMatrix(input)
        assert(actualResult.contentDeepEquals(expectedResult))
    }
}