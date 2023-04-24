class Solution {
    fun generateParenthesis(n: Int): List<String> {

        val result = mutableListOf<String>()

        fun helper(current: String, o: Int, c: Int, isValid: Int) {
            if(o < 0 || c < 0 || isValid < 0){
                return
            }

            if(o == 0 && c == 0 && isValid == 0){
                result.add(current)
                return
            }

            
            helper(current + "(", o - 1, c, isValid + 1)
            helper(current + ")", o, c - 1, isValid - 1)

        }

        helper("(", n - 1, n, 1)
        return result
    }
}