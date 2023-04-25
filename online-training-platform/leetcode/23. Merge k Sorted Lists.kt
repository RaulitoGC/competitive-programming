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


    private fun mergeHelper(l1: ListNode?, l2: ListNode?): ListNode? {
        var n1 = l1; var n2 = l2
        var result = ListNode(0); var prev = result
        while( n1 != null && n2 != null){
            
            if(n1?.`val` < n2?.`val`){
                result?.next = ListNode(n1.`val`)
                n1 = n1?.next
            } else {
                result?.next = ListNode(n2.`val`)
                n2 = n2?.next
            }

            result = result?.next
        }

        while(n1 != null){
            result?.next = ListNode(n1.`val`)
            n1 = n1?.next
            result = result?.next
        }

        while(n2 != null){
            result?.next = ListNode(n2.`val`)
            n2 = n2?.next
            result = result?.next
        }

        return prev.next
    }

    private fun helper(node: ListNode?){
        var n = node
        while(n != null){
            print("${n?.`val`} -> ")
            n = n?.next
        }
        println()
    }

    fun mergeKLists(lists: Array<ListNode?>): ListNode? {
        var result :ListNode? = null

        for(i in 0 until lists.size){
            result = mergeHelper(result, lists[i])
        }
        return result
    }
}