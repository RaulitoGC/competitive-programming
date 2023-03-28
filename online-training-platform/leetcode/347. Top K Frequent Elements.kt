class Solution {
    fun topKFrequent(nums: IntArray, k: Int): IntArray {
        val pq = PriorityQueue<Pair<Int, Int>>(){ p1, p2 ->
            p2.second - p1.second
        }

        val cache = HashMap<Int, Int>()
        nums.forEach{
            cache[it] = cache.getOrDefault(it, 0) + 1
        }

        for((k, v) in cache){
            pq.add(Pair(k,v))
        }

        val result = IntArray(k){
            0
        }

        repeat(k){ idx ->
            result[idx] = pq.poll().first
        }

        return result
    }
}