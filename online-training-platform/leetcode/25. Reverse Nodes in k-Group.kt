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

    private fun getReversed(n: ListNode?): Pair<ListNode?, ListNode?> {
        var prev: ListNode? = null
        var current = n

        while(current != null){
            val next = current?.next
            current?.next = prev

            prev = current
            current = next
        }

        current = prev
        while(current?.next != null){
            current = current?.next
        }

        // println("current = ${current?.`val`}")
        // println("prev = ${prev?.`val`}")
        return Pair(prev, current)
    }

    private fun printHelper(n: ListNode?){
        var node = n
        while(node != null){
            print(" ${node?.`val`}")
            node = node?.next
        }
        println()
    }

    private fun getLinkedListSize(n: ListNode?): Int{
        var node = n
        var size = 0
        while(node != null){
            node = node?.next
            size += 1
        }
        return size
    }

    fun reverseKGroup(head: ListNode?, k: Int): ListNode? {
        var idx = 0
        var size = getLinkedListSize(head)
        var current = head
        var result: ListNode? = null
        var prev: ListNode? = null
        
        while(idx < size){
            var i = 0
            val start = current
            
            while(i < k - 1){
                current = current?.next
                i++
            }

            val next = current?.next
            current?.next = null
            val reversed = getReversed(start)
            
            //printHelper(reversed.first)
            if(result == null){
                result = reversed.first
            }
            prev?.next = reversed.first
            prev = reversed.second
            current = next
            idx += k
            
            if(idx + k > size){
                prev?.next = current
                break
            }
        }
        
        //printHelper(result)
        return result
    }
}