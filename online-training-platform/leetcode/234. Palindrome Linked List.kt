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
    fun isPalindrome(head: ListNode?): Boolean {
        val stack = ArrayDeque<Int>()
        var size = 0

        var n = head
        while(n != null){
            n = n?.next
            size += 1
        }
        n = head
        val limit = if(size % 2 == 0) size / 2 else (size / 2) + 1
        for(idx in 0 until limit){
            n?.`val`?.let{
                stack.addFirst(it)
            }
            n = n?.next
        }

        println(stack.size)

        if(size % 2 != 0 && stack.isNotEmpty()){
            stack.removeFirst()
        }
        
        

        while(n != null && stack.isNotEmpty()){
            n?.`val`?.let{
                if(stack.peekFirst() == it){
                    stack.removeFirst()
                }
            }
            n = n?.next
        }

        return stack.isEmpty()
    }
}