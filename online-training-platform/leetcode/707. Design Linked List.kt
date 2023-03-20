
data class Node(
    val value: Int,
    var next: Node? = null
)

class MyLinkedList() {

    val head = Node(-100)



    fun get(index: Int): Int {
        
        val size = getLinkedListSize()
        if(index < 0 || index >= size){
            return -1
        }

        var idx = 0
        var prev = head
        var current = head?.next
        while(current != null && idx != index){
            prev = current
            current = current?.next
            idx += 1
        }

        return current?.value ?: -1
    }

    private fun getLinkedListSize(): Int{
        var current = head?.next
        var idx = 0
        while(current != null){
            idx += 1
            current = current?.next
        }
        return idx
    }

    fun addAtHead(`val`: Int) {
        val current = head
        val next = head?.next
        
        val nodeToAdd = Node(value = `val`)
        
        if(next == null){
            head?.next = nodeToAdd
        } else {
            current?.next = nodeToAdd
            nodeToAdd?.next = next
        }
        
    }

    fun addAtTail(`val`: Int) {
        var nodeToAdd = Node(value = `val`)
        var current: Node? = head?.next

        if(current == null){
            head?.next = nodeToAdd
            return
        }

        while(current?.next != null){
            current = current?.next
        }
        current?.next = nodeToAdd
        
    }

    fun addAtIndex(index: Int, `val`: Int) {
        val size = getLinkedListSize()
        if ( index < 0 || index > size){
            return
        }
        if(index == size){
            addAtTail(`val`)
            return
        }

        if(index == 0){
            addAtHead(`val`)
            return
        }

        var idx = 0
        var prev = head
        var current = head?.next
        val nodeToAdd = Node(value = `val`)
        while(current != null && idx != index){
            prev = current
            current = current?.next
            idx += 1
        }

        prev?.next = nodeToAdd
        nodeToAdd?.next = current
    }

    fun deleteAtIndex(index: Int) {
        val size = getLinkedListSize()
        if ( index < 0 || index >= size){
            return
        }

        var idx = 0
        var prev = head
        var current = head?.next
        while(current != null && idx != index){
            prev = current
            current = current?.next
            idx += 1
        }

        val next = current?.next
        current?.next = null
        prev?.next = next
    }

}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(`val`)
 * obj.addAtTail(`val`)
 * obj.addAtIndex(index,`val`)
 * obj.deleteAtIndex(index)
 */