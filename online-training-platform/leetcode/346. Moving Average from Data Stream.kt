class MovingAverage(private val size: Int) {
    
    private val numbers = ArrayDeque<Int>()
    private var totalSum = 0

    fun next(`val`: Int): Double {
        val currentSize = numbers.size
        
        if(currentSize >= size) {
            val numberToDelete = numbers.first()
            numbers.removeFirst()
            totalSum -= numberToDelete
        }
        
        numbers.addLast(`val`)
        totalSum += `val`
        
        return totalSum.toDouble() / numbers.size.toDouble()
    }

}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * var obj = MovingAverage(size)
 * var param_1 = obj.next(`val`)
 */