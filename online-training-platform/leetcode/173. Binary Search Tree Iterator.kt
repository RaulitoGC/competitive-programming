/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class BSTIterator(root: TreeNode?) {

    private val list = mutableListOf<Int>()
    private var pointer : Int = 0
    
    init{
        inorder(root)
    }

    private fun inorder(root: TreeNode?){
        root?.let{
            inorder(root.left)
            list.add(root.`val`)
            inorder(root.right)
        }
    }

    fun next(): Int {
        val result = list[pointer]
        pointer += 1
        return result
    }

    fun hasNext(): Boolean = pointer < list.size

}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */