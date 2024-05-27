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
    fun getIntersectionNode(headA:ListNode?, headB:ListNode?):ListNode? {
        val cache = HashSet<ListNode?>()

        var current = headA
        while(current != null){
            cache.add(current)
            current = current?.next
        }

        current = headB
        while(current != null){
            if(cache.contains(current)){
                return current
            }
            current = current?.next
        }

        return null
    }
}