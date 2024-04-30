package util

object PrintHelper {

    private const val TAG = "PrintHelper"

    fun matrix(matrix: Array<IntArray>, tag: String? = null){
        print("============== ${tag ?: TAG} ====================")
        println()
        val indices = matrix.indices
        for(i in indices){
            for(j in indices){
                print(" ${matrix[i][j]}")
            }
            println()
        }
        println()
    }
}