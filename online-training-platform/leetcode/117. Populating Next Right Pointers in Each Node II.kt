/**
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var left: Node? = null
 *     var right: Node? = null
 *     var next: Node? = null
 * }
 */

 class Solution {
    fun connect(root: Node?): Node? {
        if(root != null){
            val queue = ArrayDeque<Node>()
            queue.addLast(root)

            while(queue.isNotEmpty()){
                val size = queue.size

                for(idx in 0 until size){
                    val current : Node = queue.peekFirst()
                    queue.removeFirst()

                    
                    val next : Node? = if(idx < size - 1) {
                        queue.peekFirst()
                    } else {
                        null
                    }
                
                    if(next != null) {
                        current.next = next
                    }

                    if(current.left != null){
                        queue.addLast(current.left)
                    }
                    
                    if(current.right != null){
                        queue.addLast(current.right)
                    }
                    
                }
            }
        }
        
        return root
    }
}