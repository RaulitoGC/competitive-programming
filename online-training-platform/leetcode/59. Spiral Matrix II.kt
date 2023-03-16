class Solution {
    fun generateMatrix(n: Int): Array<IntArray> {

        if(n == 1){
            return Array<IntArray>(1){
                IntArray(1){
                    1
                }
            }
        }
        
        val cycle = (n / 2) + (n % 2)
        
        var rightFirst = 0; var rightSecond = 0
        var bottomFirst = 0; var bottomSecond = n - 1
        var leftFirst = n - 1; var leftSecond = n - 1
        var topFirst = n - 1; var topSecond = 0
        var value = 1
        var matrix = Array<IntArray>(n){
            IntArray(n){
                0
            }
        }
        repeat(cycle){
            val right = Pair(rightFirst, rightSecond)
            val bottom = Pair(bottomFirst, bottomSecond)
            val left = Pair(leftFirst, leftSecond)
            val top = Pair(topFirst, topSecond)
            

            for(j in rightSecond until bottomSecond) {
                if(value > n * n) break
                matrix[rightFirst][j] = value
                value += 1
            }

            for(i in bottomFirst until leftFirst){
                if(value > n * n) break
                matrix[i][bottomSecond] = value
                value += 1
            }

            var idx = leftSecond
            while( idx > topSecond) {
                if(value > n * n) break
                matrix[leftFirst][idx] = value
                idx -= 1
                value += 1
            }

            
            idx = topFirst
            while( idx > rightFirst) {
                if(value > n * n) break
                matrix[idx][topSecond] = value
                idx -= 1
                value += 1
            }

            rightFirst += 1
            rightSecond += 1

            bottomFirst += 1
            bottomSecond -= 1

            leftFirst -= 1
            leftSecond -= 1

            topFirst -= 1
            topSecond += 1


        }

        if(n % 2 == 1) {
            matrix[n/2][n/2] = n*n
        }
        

        return matrix
    }
}