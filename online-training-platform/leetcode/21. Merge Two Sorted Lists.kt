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
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        var first = list1; var second = list2
        var result: ListNode? = ListNode(-1); val prev = result

        while(first != null && second != null) {
            if(first?.`val` < second?.`val`) {
                result?.next = first
                first = first?.next
            } else {
                result?.next = second
                second = second?.next
            }
            result = result?.next
        }

        while(first != null ) {
            result?.next = first
            first = first?.next
            result = result?.next    
        }

        while(second != null) {
            result?.next = second
            second = second?.next
            result = result?.next
        }

        return prev?.next
    }
}