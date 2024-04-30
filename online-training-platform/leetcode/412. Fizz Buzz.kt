class Solution {
    fun fizzBuzz(n: Int): List<String> {
        val answers = MutableList<String>(n){""}
        for(answer in 1..n){
            val result = when{
                answer % 3 == 0 && answer % 5 == 0 -> "FizzBuzz"
                answer % 3 == 0 -> "Fizz"
                answer % 5 == 0 -> "Buzz"
                else -> "$answer"
            }
            answers[answer - 1] = result
        }

        return answers
    }
}