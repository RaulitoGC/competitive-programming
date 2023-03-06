class Solution {
    fun uniquePaths(m: Int, n: Int): Int {
        val arr = IntArray(n){1}

        for(i in 1 until m){
            for(j in 1 until n) {
                arr[j] = arr[j] + arr[j - 1]
            }
        }

        return arr[n - 1]
    }
}