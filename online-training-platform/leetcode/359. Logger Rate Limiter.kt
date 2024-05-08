class Logger() {

    private val cache = HashMap<String, Int>()

    // foo = 11
    // bar = 12

    // Time = O(1)
    // Space = O(#calls)
    fun shouldPrintMessage(timestamp: Int, message: String): Boolean {
        
        if(cache.contains(message)){
            val lastTimeStamp = cache.getOrDefault(message, -1)
            if(timestamp >= lastTimeStamp){
                cache[message] = timestamp + 10
                return true
            } else {
                return false
            }
        } else {
            cache[message] = timestamp + 10
            return true
        }
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * var obj = Logger()
 * var param_1 = obj.shouldPrintMessage(timestamp,message)
 */