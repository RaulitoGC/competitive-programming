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
    fun reverseList(head: ListNode?): ListNode? {
        var prev: ListNode? = head
        var current: ListNode? = head?.next
        var next: ListNode? = head?.next?.next

        if(prev == null) {
            return null
        }

        if(current == null) {
            return prev
        }

        prev?.next = null
        if(next == null) {
            current?.next = prev
            return current
        }

        while(current != null) {
            current?.next = prev
            prev = current
            current = next
            next = next?.next
        }

        return prev
    }
}