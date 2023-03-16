class Solution {
    fun getRow(rowIndex: Int): List<Int> {
        return when(rowIndex) {
            0 -> listOf(1)
            1 -> listOf(1,1)
            2 -> listOf(1,2,1)
            else -> {
                var current = getRow(2)
                var result = mutableListOf(1)
                for(idx in 2 until rowIndex){
                    result = mutableListOf(1)
                    for(j in 1 until current.size) {
                        result.add(current[j] + current[j - 1])
                    }
                    result.add(1)
                    current = result
                }
                result
            }
        }
    }
}