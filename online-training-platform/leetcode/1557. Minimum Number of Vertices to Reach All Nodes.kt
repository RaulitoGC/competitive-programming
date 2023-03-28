class Solution {
    fun findSmallestSetOfVertices(n: Int, edges: List<List<Int>>): List<Int> {
        val cache = HashSet<Int>()
        repeat(n){ idx ->
            cache.add(idx)
        }

        edges.forEach{
            val from = it.first()
            val to = it.last()
            if(cache.contains(to)){
                cache.remove(to)
            }
        }

        return cache.toList()
    }
}