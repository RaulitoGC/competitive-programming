class RandomizedSet() {

    private val list = mutableListOf<Int>()
    private val cache = HashMap<Int,Int>()                       

    fun insert(`val`: Int): Boolean {
        return if(cache.contains(`val`)) {
            false
        } else {
            cache[`val`] = list.size
            list.add(`val`)
            true
        }
    }

    fun remove(`val`: Int): Boolean {
        return if(cache.contains(`val`)) {
            val lastIdx = list.size - 1
            val idx = cache.getOrDefault(`val`, lastIdx)
            cache[list[lastIdx]] = idx
            list[idx] = list[lastIdx].also{
                list[lastIdx] = list[idx]
            }
            list.removeLast()
            cache.remove(`val`)
            true
        } else {
            false
        }
    }

    fun getRandom(): Int {
        if(list.size == 1){
            return list.first()
        }
        val randomIdx = kotlin.random.Random.nextInt(1, list.size + 1)
        return list[randomIdx - 1]
    }

}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = RandomizedSet()
 * var param_1 = obj.insert(`val`)
 * var param_2 = obj.remove(`val`)
 * var param_3 = obj.getRandom()
 */