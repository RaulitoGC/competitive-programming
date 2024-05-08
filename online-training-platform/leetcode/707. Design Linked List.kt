data class Node(
    var next: Node? = null,
    val value: Int
)

class MyLinkedList() {

    private var head: Node? = null
    private var size = 0

    fun get(index: Int): Int {
        if(index < 0 || index >= size){
            return -1
        }

        var current = head
        for(idx in 0 until index){
            current = current?.next
        }

        return current?.value ?: -1
    }

    fun addAtHead(`val`: Int) {
        val node = Node(
            value = `val`
        )
        node?.next = head
        head = node
        size += 1
    }

    fun addAtTail(`val`: Int) {
        if(head == null){
            addAtHead(`val`)
            return
        }

        var current = head
        while(current?.next != null){
            current = current?.next
        }
        val node = Node(value = `val`)
        current?.next = node
        size += 1
    }

    fun addAtIndex(index: Int, `val`: Int) {
        if(index == size){
            addAtTail(`val`)
            return
        }

        if(index > size){
            return
        }

        if(index == 0){
            addAtHead(`val`)
            return
        }

        var current = head
        for(idx in 0 until index - 1){
            current = current?.next
        }

        val node = Node(value = `val`)
        val next = current?.next
        current?.next = node
        node?.next = next
        size += 1
    }

    fun deleteAtIndex(index: Int) {
        if(index < 0 || index >= size){
            return
        }

        size -= 1
        if(index == 0){
            head = head?.next
            return
        }

        var current = head
        for(idx in 0 until index - 1){
            current = current?.next
        }
        val next = current?.next
        current?.next = next?.next
        
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