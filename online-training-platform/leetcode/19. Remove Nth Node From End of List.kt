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
    fun removeNthFromEnd(head: ListNode?, n: Int): ListNode? {
        var current = head
        var size = 0
        while(current != null) {
            size += 1
            current = current?.next
        }

        if(size == n){
            return head?.next
        }

        current = head
        repeat(size - n - 1) {
            current = current?.next
        }

        val next = current?.next
        current?.next = next?.next

        return head
    }
}