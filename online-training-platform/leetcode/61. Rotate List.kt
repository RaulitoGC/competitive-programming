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

    private fun getRotationNumber(size: Int, k: Int) : Int {
        if(size == 0 || k == 0){
            return 0
        }
        return k % size
    }

    private fun getLastNode(head: ListNode?): ListNode? {
        var current = head
        while(current?.next != null){
            current = current?.next
        }

        return current
    }

    private fun getNodeToBeNextRemoved(head: ListNode?, steps: Int) : ListNode?{
        var current = head
        var idx = 0
        while(idx < steps ){
            current = current?.next
            idx += 1
        }

        return current
    }

    private fun getListNodeSize(head: ListNode?): Int {
        var current = head
        var size = 0
        while(current != null){
            current = current?.next
            size += 1
        }

        return size
    }

    fun rotateRight(head: ListNode?, k: Int): ListNode? {
        
        val size = getListNodeSize(head)
        val rotations = getRotationNumber(size, k)
        if(size <= 1 || rotations == 0){
            return head
        }
        
        val nodeToNextRemoved = getNodeToBeNextRemoved(head, size - rotations - 1)
        val lastNode = getLastNode(head)

        val result = nodeToNextRemoved?.next
        nodeToNextRemoved?.next = null
        lastNode?.next = head

        return result
    }
}