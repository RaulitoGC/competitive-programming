class Solution {

    private val father = mutableListOf<Int>()

    private fun union(a: Int, b : Int){
        father[find(a)] = father[find(b)]
    }

    private fun find(a: Int): Int {
        return if(father[a] == a){
            a
        } else {
            father[a] = find(father[a])
            return father[a]
        }
    }

    fun findCircleNum(isConnected: Array<IntArray>): Int {
        val n = isConnected.size
        repeat(n){ idx ->
            father.add(idx)
        }

        isConnected.forEachIndexed{ i, row ->
            row.forEachIndexed{ j, cell ->
                if(cell == 1 && i != j){
                    union(i, j)
                }
            }
        }

        var provinces = 0
        father.forEachIndexed{ idx, f ->
            if(f == idx){
                provinces += 1
            }
        }
    
        return provinces
    }
}