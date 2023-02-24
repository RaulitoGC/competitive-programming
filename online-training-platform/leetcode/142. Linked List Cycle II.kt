/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list. 
 */

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}


class Solution {

/*
    * Return null if there is no cycle, otherwise a node
    */
    private fun hasCycle(head: ListNode?) : ListNode? {
        var first = head; var second = head
        while(second != null) {
            first = first?.next
            second = second?.next?.next
            if(first == second) {
                break
            }
        }

        return second
    }

    fun detectCycle(head: ListNode?): ListNode? {
        var matchNode = hasCycle(head)
        if(matchNode == null){
            return null
        }
        
        var first = head
        
        while(first != matchNode) {
            first = first?.next
            matchNode = matchNode?.next
        }
        return first
    }
}