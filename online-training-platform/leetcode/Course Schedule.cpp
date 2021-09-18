class Solution {
  
    companion object{
      const val NOT_VISITED = 0
      const val VISITING = 1
      const val VISITED = 2
    }
  
    val graph = mutableListOf<MutableList<Int>>()
    val state = mutableListOf<Int>()
    
    fun hasCycle(node: Int): Boolean{
      if(state[node] == VISITING) {
        return true
      }
      
      if(state[node] == NOT_VISITED){
        state[node] = VISITING
        for(child in 0 until graph[node].size){
          if(hasCycle(graph[node][child])){
            return true
          }
        }
      }
      
      state[node] = VISITED
      return false
    }
  
    fun canFinish(numCourses: Int, prerequisites: Array<IntArray>): Boolean {
      
      for(i in 0 until numCourses){
        graph.add(mutableListOf<Int>())
        state.add(NOT_VISITED)
      }
      
      for(i in 0 until prerequisites.size){
        graph[prerequisites[i][1]].add(prerequisites[i][0])
      }
      
      for(node in 0 until numCourses){
        if(hasCycle(node)){
          return false
        }
      }
      
      return true
    }
}