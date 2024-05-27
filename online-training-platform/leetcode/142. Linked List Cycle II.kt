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
    fun detectCycle(head: ListNode?): ListNode? {
        var slow = head
        var fast = head
        var flag = true
        while(slow != fast || flag){
            slow = slow?.next
            fast = fast?.next?.next
            flag = false
        }

        var result = head
        while(result != slow){
            result = result?.next
            slow = slow?.next
        }
        
        return result
    }
}