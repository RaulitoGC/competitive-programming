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
    
    var target: Double = 0.0
    var minValue: Double = 0.0
    var result: Int = 0 
    
    private fun traverseTree(root: TreeNode?) {
        root?.let{
            if(target < it.`val`.toDouble()){
                val currentMin = it.`val`.toDouble() - target
                // println("left-> ${it.`val`} - $currentMin , $minValue")
                if(currentMin <= minValue){
                    result = if(currentMin == minValue){
                        min(result, it.`val`)
                    } else {
                        it.`val`
                    }
                    minValue = currentMin
                }
                // println("left -> $result")
                traverseTree(it.left)
            } else if ( target > it.`val`.toDouble()){
                val currentMin = target - it.`val`.toDouble()
                // println("right -> ${it.`val`} - $currentMin , $minValue")
                if(currentMin <= minValue){
                    result = if(currentMin == minValue){
                        min(result, it.`val`)
                    } else {
                        it.`val`
                    }
                    minValue = currentMin
                }
                // println("right -> $result")
                traverseTree(it.right)
            } else {
                // println("equals")
                result = it.`val`
                minValue = 0.0
            }
        }
    }
    
    fun closestValue(root: TreeNode?, target: Double): Int {
        this.target = target
        
        root?.let{
            result = it.`val`
            
            if(target < it.`val`.toDouble()){
                minValue = it.`val`.toDouble() - target
                traverseTree(it.left)
            } else if ( target > it.`val`.toDouble()){
                minValue = target - it.`val`.toDouble()
                traverseTree(it.right)
            }
        } 
        
        return result
    }
}