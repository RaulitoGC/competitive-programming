/**
 * Example:
 * var ti = Node(5)
 * var v = ti.`val`
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var next: Node? = null
 *     var random: Node? = null
 * }
 */

class Solution {
  
    val visited = HashMap<Node, Node>()
  
    fun copyRandomList(node: Node?): Node? {
      if(node == null) return null
        
      if(visited.contains(node!!)){
        return visited[node!!]
      }
      
      val newNode = Node(node!!.`val`)
      visited[node!!] = newNode
      
      newNode.next = copyRandomList(node?.next)
      newNode.random = copyRandomList(node?.random)

      return newNode
    }
}