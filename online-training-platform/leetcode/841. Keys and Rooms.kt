class Solution {
    fun canVisitAllRooms(rooms: List<List<Int>>): Boolean {
        val visited = BooleanArray(rooms.size){
            false
        }

        val queue = ArrayDeque<Int>()
        queue.addLast(0)
        visited[0] = true

        while(queue.isNotEmpty()){
            val size = queue.size
            repeat(size){
                val idx = queue.peekFirst()
                queue.removeFirst()

                rooms[idx].forEach{ key ->
                    if(visited[key].not()){
                        visited[key] = true
                        queue.addLast(key)
                    }
                }
            }
        }
        
        return visited.filter{!it}.isEmpty()
    }
}