class Solution {

    private fun helper(matrix : Array<BooleanArray>) {
        for(i in 0 until matrix.size){
            for(j in 0 until matrix[0].size){
                print(" ${matrix[i][j]}")
            }
            println()
        }
        println()
    }

    fun isMatch(s: String, p: String): Boolean {
        val n = s.length
        var m = p.length

        var isFirst = true
        val sb = StringBuilder()
        for(i in 0 until m){
            if(p[i] == '*'){
                if(isFirst){
                    sb.append(p[i])
                    isFirst = false
                }
            } else {
                sb.append(p[i])
                isFirst = true
            }
        }

        val pattern = sb.toString()
        //println(pattern)
        m = pattern.length
        val matrix = Array<BooleanArray>(n + 1){
            BooleanArray(m + 1){
                false
            }
        }

        matrix[0][0] = true
        if(m > 0 && pattern[0] == '*'){
            matrix[0][1] = true
        }

        //helper(matrix)

        for(i in 1 until n + 1){
            for(j in 1 until m + 1){
                if(pattern[j - 1] == '?' || s[i - 1] == pattern[j - 1]){
                    matrix[i][j] = matrix[i-1][j-1]
                } else if(pattern[j - 1] == '*'){
                    matrix[i][j] = matrix[i - 1][j] || matrix[i][j - 1]
                } else{
                    matrix[i][j] = false
                }
            }
            //helper(matrix)
        }

        return matrix[n][m]
    }
}