class TwoSum() {

    private val cache = HashMap<Int, Boolean>()

    fun add(number: Int) {
        cache[number] = cache.contains(number)
    }

    fun find(value: Int): Boolean {
        
        var result = false
        cache.forEach{ k, v ->
            if(cache.contains(value - k)){
                result = if(value - k != k) true else cache.getOrDefault(value - k, false)
            }
        }

        return result
    }

}

/**
 * Your TwoSum object will be instantiated and called as such:
 * var obj = TwoSum()
 * obj.add(number)
 * var param_2 = obj.find(value)
 */