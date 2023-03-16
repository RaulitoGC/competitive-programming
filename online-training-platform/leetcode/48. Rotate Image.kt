class Solution {
    fun rotate(matrix: Array<IntArray>): Unit {
        val size = matrix.size
        val cycle = size / 2

        var rightFirst = 0; var rightSecond = 0
        var bottomFirst = 0; var bottomSecond = size - 1
        var leftFirst = size - 1; var leftSecond = size - 1
        var topFirst = size - 1; var topSecond = 0
        var range = size - 1

        repeat(cycle) { idx ->
            var right = Pair(rightFirst, rightSecond)
            var bottom = Pair(bottomFirst, bottomSecond)
            var left = Pair(leftFirst, leftSecond)
            var top = Pair(topFirst, topSecond)

            repeat(range){
                var temp = matrix[bottom.first][bottom.second]
                matrix[bottom.first][bottom.second] = matrix[right.first][right.second]

                matrix[left.first][left.second] = temp.also{
                    temp = matrix[left.first][left.second]
                }
                
                matrix[top.first][top.second] = temp.also{
                    temp = matrix[top.first][top.second]
                }

                matrix[right.first][right.second] = temp

                right = Pair(right.first, right.second + 1)
                bottom = Pair(bottom.first + 1, bottom.second)
                left = Pair(left.first, left.second - 1)
                top = Pair(top.first - 1, top.second)
            }

            range -= 2
            
            matrix.forEach{ row ->
                row.forEach{ c ->
                    print("$c ")
                }
                println()
            }

            println()

            rightFirst = rightFirst + 1;
            rightSecond = rightSecond + 1

            bottomFirst = bottomFirst + 1
            bottomSecond = bottomSecond - 1
            
            leftFirst = leftFirst - 1
            leftSecond = leftSecond - 1
            
            topFirst = topFirst - 1
            topSecond = topSecond + 1
            
            println("$rightFirst, $rightSecond")
            println("$bottomFirst, $bottomSecond")
            println("$leftFirst, $leftSecond")
            println("$topFirst, $topSecond")
        }
    }
}