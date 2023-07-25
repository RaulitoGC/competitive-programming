package array_string

import Question
import util.PrintHelper

/**
 * Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
 * bytes, write a method to rotate the image by 90 degrees. (an you do this in place?
 */

fun Question.rotateMatrix(matrix: Array<IntArray>): Array<IntArray> {
    return when (level) {
        Level.BASIC -> rotateMatrixBasicImplementation(matrix)
        else -> throw NotImplementedError("This problem does not contain ${level.name} implementation")
    }
}


private fun rotateMatrixBasicImplementation(matrix: Array<IntArray>): Array<IntArray> {

    val n = matrix.size

    fun reverseRow(row: Int){
        for(j in 0 until n / 2){
            matrix[row][j] = matrix[row][n - j - 1].also {
                matrix[row][n - j - 1] = matrix[row][j]
            }
        }
    }

    for(i in 0 until n){
        reverseRow(i)
    }

    PrintHelper.matrix(matrix)
    for(i in 0 until n) {
        for( j in 0 until i){
            matrix[i][j] = matrix[j][i].also{
                matrix[j][i] = matrix[i][j]
            }
        }
    }

    return matrix
}
