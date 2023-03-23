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
class Solution {

    private var idx = 1

    fun buildNodeHelper(preorder: IntArray, inorder: IntArray, start: Int, end: Int): TreeNode?{
        
        if(start > end){
            return null
        }

        if(start == end){
            idx += 1
            return TreeNode(inorder[start])
        }

        val rootValue = preorder[idx]
        val rootIdxInInorder = inorder.indexOf(rootValue)

        return TreeNode(rootValue).apply{
            idx += 1
            left = buildNodeHelper(preorder, inorder, start, rootIdxInInorder - 1)
            right = buildNodeHelper(preorder, inorder, rootIdxInInorder + 1, end)
        }
    }

    fun buildTree(preorder: IntArray, inorder: IntArray): TreeNode? {
        val rootValue = preorder[0]
        val rootIdxInInorder = inorder.indexOf(rootValue)

        return TreeNode(rootValue).apply{
            left = buildNodeHelper(preorder, inorder, 0, rootIdxInInorder - 1)
            right = buildNodeHelper(preorder, inorder, rootIdxInInorder + 1, inorder.size - 1)
        }
    }
}