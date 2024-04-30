package array_string

import Level
import Question
import org.junit.jupiter.api.Test

class OneWayTest {

    @Test
    fun testBasicImplementation_resultOneTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val str1 = "pale"; val str2 = "ple"
        val expectedResult = true
        val actualResult = problem.oneAway(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testBasicImplementation_resultTwoTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val str1 = "pales"; val str2 = "pale"
        val expectedResult = true
        val actualResult = problem.oneAway(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testBasicImplementation_resultThreeTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val str1 = "pale"; val str2 = "bale"
        val expectedResult = true
        val actualResult = problem.oneAway(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testBasicImplementation_resultFourTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.BASIC
        }

        val str1 = "pale"; val str2 = "bake"
        val expectedResult = false
        val actualResult = problem.oneAway(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultOneTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val str1 = "pale"; val str2 = "ple"
        val expectedResult = true
        val actualResult = problem.oneAway(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultTwoTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val str1 = "pales"; val str2 = "pale"
        val expectedResult = true
        val actualResult = problem.oneAway(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultThreeTrue() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val str1 = "pale"; val str2 = "bale"
        val expectedResult = true
        val actualResult = problem.oneAway(str1, str2)
        assert(actualResult == expectedResult)
    }

    @Test
    fun testIntermediateImplementation_resultFalse() {
        val problem = object : Question {
            override val level: Level
                get() = Level.INTERMEDIATE
        }

        val str1 = "pale"; val str2 = "bake"
        val expectedResult = false
        val actualResult = problem.oneAway(str1, str2)
        assert(actualResult == expectedResult)
    }
}