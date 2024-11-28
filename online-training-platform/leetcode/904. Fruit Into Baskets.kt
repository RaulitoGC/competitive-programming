class Solution {

    // Time: O(N*N)
    // Space: O(1)
    fun totalFruit(fruits: IntArray): Int {
        
        var i = 0
        var basket1 = -1; var basket2 = -1
        var result = 0
        while(i < fruits.size){
            var start = i
            basket1 = -1
            basket2 = -1
            while(start < fruits.size) {
                val current = fruits[start]
                // println("$i - current -> $current")
                if(basket1 == -1 || (basket1 != -1 && current == basket1)) {
                    basket1 = current
                    start += 1
                    continue
                } else if(basket2 == -1 || (basket2 != -1 && current == basket2)){
                    basket2 = current
                    start += 1
                    continue
                }
                
                if(current != basket1 && current != basket2) {
                    result = max(result, start - i)
                    break
                }
                
                start += 1
            }
            // println("start -> $start - $i")
            result = max(result, start - i)
            i += 1                                                                                      
        }
        
        return result
    }
}