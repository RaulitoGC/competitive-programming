class Solution {

    // Time Complexity = O(log(n))
    // Space Complexity = O(1)
    fun numberOfSteps(num: Int): Int {
        var steps = 0

        var number = num
        while(number > 0){
            
            number = if(number % 2 == 0) number / 2 else number - 1

            steps += 1
        }

        return steps
    }
}