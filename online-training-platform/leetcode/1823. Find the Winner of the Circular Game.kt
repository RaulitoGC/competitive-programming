data class Node(
    val value: Int,
    var next: Node? = null
)

class Solution {

    private fun helper(n: Node?){
        var current = n
        repeat(5){
            print(" ${current?.value}")
            current = current?.next
        }
        println()
    }

    fun findTheWinner(n: Int, k: Int): Int {
        if(n == 1){
            return 1
        }

        val head = Node(1)
        var current: Node? = head
        for(idx in 1 until n){
            current?.next = Node(idx + 1)
            current = current?.next
        }
        current?.next = head

        // helper(head)
        current = head
        var prev: Node? = null
        var count = 1
        var i = 0
        while(i < n - 1){
            val end = count + k - 1
            while(count < end){
                prev = current
                current = current?.next
                count += 1
            }
            
            val next = current?.next
            // println("prev = ${prev?.value}")
            // println("current = ${current?.value}")
            // println("next = ${next?.value}")
            // println()
            current?.next = null
            prev?.next = next
            i += 1
            current = next
            // helper(current)
        }

        return current?.value ?: 0
    }
}