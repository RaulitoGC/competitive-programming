/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {


    private fun getReversed(n: ListNode?): ListNode?{
        var prev: ListNode? = null
        var current = n
        while(current != null){
            val next = current?.next
            current?.next = prev
            prev = current
            current = next
        }

        return prev
    }

    fun printHelper(node: ListNode?){
        var n = node
        while(n != null){
            print(" ${n.`val`}")
            n = n?.next
        }
    }

    fun reorderList(head: ListNode?): Unit {

        var size  = 0
        var node = head
        while(node != null){
            node = node?.next
            size += 1
        }

        node = head
        var idx = 0
        while(idx < (size / 2) - 1){
            node = node?.next
            idx += 1
        }

        var next = node?.next
        node?.next = null
        var reversed = getReversed(next)
        node = head

        var nodeNext: ListNode? = null
        var reversedNext: ListNode? = null
        var prev : ListNode? = null

        while(node != null && reversed != null){
            nodeNext = node?.next
            reversedNext = reversed?.next

            node?.next = reversed
            reversed?.next = nodeNext

            prev = reversed
            node = nodeNext
            reversed = reversedNext

        }
        

        if(reversed != null){
            prev?.next = reversed
        }
    }
}