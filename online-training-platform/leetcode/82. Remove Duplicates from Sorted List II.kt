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
    fun deleteDuplicates(head: ListNode?): ListNode? {
        if(head == null ) return null
        val aux : ListNode? = ListNode(-110)
        aux?.next = head
        var prev = aux
        var current = head
        var next = current?.next

        while(current != null){
            // println("prev -> ${prev?.`val`}")
            // println("current -> ${current?.`val`}")
            next = current?.next
            // println("nexty -> ${next?.`val`}")
            if(current?.`val` == next?.`val`){
                while(next != null && next?.`val` == current?.`val`){
                    next = next?.next
                }
                prev?.next = next
                // println("next -> ${next?.`val`}")
            } else {
                prev = current
            }
            current = next
            // println()
        }

        return aux?.next
    }
}