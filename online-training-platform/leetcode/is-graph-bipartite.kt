class Solution {
    fun isBipartite(graph: Array<IntArray>): Boolean {
        val n = graph.size
        val color = IntArray(n){ -1}
        
        for(node in 0 until n){
            if(color[node] == -1) {
                color[node] = 0
                val stack = ArrayDeque<Int>()
                stack.addFirst(node)
                
                while(!stack.isEmpty()) {
                    val current = stack.peekFirst()
                    stack.removeFirst()
                    
                    for(idx in 0 until graph[current].size) {
                        val child = graph[current][idx]
                        if(color[child] == -1) {
                            stack.addFirst(child)
                            color[child] = color[current] xor 1
                        } else if(color[child] == color[current]) {
                            return false
                        }
                    }
                }
            }
        }
        
        return true
    }
}