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
        if(headA != null && headB != null){
            if(headA?.next == headB){
                return headB
            }

            if(headB?.next == headA){
                return headA
            }

            val cache = HashSet<ListNode>()

            var n1 = headA; var n2 = headB
            cache.add(n1)

            n1 = n1?.next
            while(n1 != null){
                n1?.let{
                    cache.add(it)
                }
                n1 = n1?.next
            }

            while(n2 != null){
                n2?.let{
                    if(cache.contains(it)){
                        return it
                    }

                    cache.add(it)
                }
                n2 = n2?.next
            }

        }



        return null 
    }
}