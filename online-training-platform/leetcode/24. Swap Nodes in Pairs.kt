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


    fun printHelper(head: ListNode?){
        var n = head
        while(n != null){
            print(n?.`val`)
            print(" ")
            n = n?.next
        }
        println()
    }

    fun swapPairs(head: ListNode?): ListNode? {
        if(head == null){
            return null
        }

        if(head?.next == null){
            return head
        }

        var aux: ListNode? = ListNode(-100)
        aux?.next = head?.next

        var prev: ListNode? = ListNode(-11)
        var current = head
        var next = current?.next

        while(current != null) {

            // println("prev -> ${prev?.`val`}")
            // println("current -> ${current?.`val`}")
            // println("next -> ${next?.`val`}")
            
            
            val nnext = next?.next
            current?.next = null
            next?.next = current
            if(next != null) {
                current = next?.also{
                    next = current
                }
            }
            

            prev?.next = current
            prev = next


            current = nnext
            next = current?.next
            
            //printHelper(aux?.next)
            //current = null
        }

        return aux?.next
    }
}