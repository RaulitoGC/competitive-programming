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
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        
        var n1 = l1; var n2 = l2
        var result : ListNode? = ListNode(-1); var prev = result
        var carry = 0
        
        while(n1 != null && n2 != null){
            val current = (n1?.`val` ?: 0) + (n2?.`val` ?: 0) + carry
            result?.next = ListNode(current % 10)
            result = result?.next
            carry = current / 10

            n1 = n1?.next
            n2 = n2?.next
        }

        while(n1 != null){
            val current = (n1?.`val`?: 0) + carry
            result?.next = ListNode(current % 10)
            result = result?.next
            carry = current / 10

            n1 = n1?.next
        }

        while(n2 != null){
            val current = (n2?.`val`?: 0) + carry
            result?.next = ListNode(current % 10)
            result = result?.next
            carry = current / 10
            
            n2 = n2?.next
        }

        if(carry != 0){
            result?.next = ListNode(carry)
        }

        return prev?.next
    }
}