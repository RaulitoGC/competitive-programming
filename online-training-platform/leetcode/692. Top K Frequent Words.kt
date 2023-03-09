class Solution {
    fun topKFrequent(words: Array<String>, k: Int): List<String> {

        
        val pq = PriorityQueue<Pair<String,Int>>(){ p1, p2 ->
            if(p2.second != p1.second )
                p2.second - p1.second
            else
                p1.first.compareTo(p2.first)
        }

        val counter = TreeMap<String, Int>()
        words.sorted().forEach{
            counter[it] = counter.getOrDefault(it, 0) + 1
        }

        for((k,v) in counter) {
            pq.add(Pair(k,v))
        }

        val result = mutableListOf<String>()
        repeat(k){
            result.add(pq.peek().first)
            pq.poll()
        }

        return result
    }
}