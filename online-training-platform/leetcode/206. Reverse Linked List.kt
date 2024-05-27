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
        if(head == null) {
            return null
        }

        var current = head 
        var next = current?.next 
        var nextNext = next?.next
        current?.next = null

        while(next != null) {
            next?.next = current
            current = next
            next = nextNext
            nextNext = next?.next
        }

        return current

    }
}