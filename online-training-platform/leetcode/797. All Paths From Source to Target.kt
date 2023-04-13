class Solution {

    data class Node(
        val key: Int,
        val children: MutableList<Node> = mutableListOf<Node>()
    )

    val result = mutableListOf<List<Int>>()

    fun dfs(graph: HashMap<Int, Node>, node: Node, target: Int, path: List<Int>){
        val newPath = path + listOf(node.key)
        if(newPath[newPath.size - 1] == target){
            result.add(newPath)
        }
        
        graph[node.key]?.children?.forEach{
            dfs(graph, it, target, newPath)
        }
    }


    fun allPathsSourceTarget(graph: Array<IntArray>): List<List<Int>> {
        
        val root = HashMap<Int, Node>()

        for(i in 0 until graph.size){
            root[i] = Node(i)
            for(j in 0 until graph[i].size){
                root[i]?.children?.add(Node(graph[i][j]))
            }
        }

        
        
        val target = graph.size - 1
        root[0]?.children?.forEach{
            dfs(root, it, target, listOf(0))
        }

        return result
    }
}