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

    private fun getSizeOfLinkedList(head: ListNode?): Int {
        var count = 0
        var current = head
        while(current != null){
            current = current?.next
            count += 1
        }
        return count
    }

    fun middleNode(head: ListNode?): ListNode? {
        val count = getSizeOfLinkedList(head); var idx = 0
        var current = head
        while(idx < count / 2){
            current = current?.next
            idx += 1
        }

        return current
    }
}