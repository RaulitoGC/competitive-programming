/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

 class Codec() {

    private fun preOrder(root: TreeNode?, current: StringBuilder): String{
        root?.let{
            current.append("${it.`val`},")
            preOrder(it.left, current)
            preOrder(it.right, current)
        } ?: run {
            current.append("null,")
        }
        return current.toString()
    }

	// Encodes a URL to a shortened URL.
    fun serialize(root: TreeNode?): String = preOrder(root, StringBuilder())

    private fun buildTree(preorder: MutableList<String>): TreeNode?{
        if(preorder.isEmpty()){
            return null
        }
        if(preorder.first() == "null"){
            preorder.removeAt(0)
            return null
        }
        
        val rootValue = preorder.first().toInt()
        preorder.removeAt(0)
    
        return TreeNode(rootValue).apply{
            left = buildTree(preorder)
            right = buildTree(preorder)
        }
    }

    // Decodes your encoded data to tree.
    fun deserialize(data: String): TreeNode? {
        val result = data.split(",")
        return buildTree(result.toMutableList())
    }
}

/**
 * Your Codec object will be instantiated and called as such:
 * var ser = Codec()
 * var deser = Codec()
 * var data = ser.serialize(longUrl)
 * var ans = deser.deserialize(data)
 */