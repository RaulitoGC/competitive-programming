class Solution {

    private fun getString(data: Char, count: Int): String{
        var result = StringBuilder()
        repeat(count){
            result.append(data)
        }
        return result.toString()
    }

    fun frequencySort(s: String): String {
        val pq = PriorityQueue<Pair<Char, Int>>(){ p1, p2 ->
            p2.second - p1.second
        }

        val count = s.groupingBy{it}.eachCount()
        for((k,v) in count){
            pq.add(Pair(k,v))
        }

        val result = StringBuilder()
        while(pq.isNotEmpty()){
            val (data, count) = pq.peek()
            pq.poll()
            result.append(getString(data, count))
        }

        return result.toString()
    }
}