class Solution {
    
    val result = mutableListOf<Int>()
    
    fun flips(arr: IntArray, point: Int) {
        
        if(point < 1){
            return
        } 
        
        val index = arr.indexOf(point)
        if(index == point - 1){
            flips(arr, point - 1)
            return
        }
        
        var i = 0
        while(i <= index / 2){
            arr[i] = arr[index - i].also{
                arr[index - i] = arr[i]
            }
            
            i += 1
        }
        result.add(index + 1)
        
        val size = point
        for(i in 0 until size / 2){
            arr[i] = arr[size - i - 1].also{
                arr[size - i - 1] = arr[i]
            }
        }
        
        result.add(size)
        
        flips(arr, point - 1)
    }
    
    fun pancakeSort(arr: IntArray): List<Int> {
        flips(arr, arr.size)
        return result
    }
}