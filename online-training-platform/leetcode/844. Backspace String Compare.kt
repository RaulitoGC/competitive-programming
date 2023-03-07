class Solution {

    private val BACKSPACE = '#'

    fun getStringHelper(s: String): String {
        val stack = ArrayDeque<Char>()
        s.forEach {
            if(it == BACKSPACE && stack.isNotEmpty()){
                stack.removeFirst()
            } else if( it != BACKSPACE) {
                stack.addFirst(it)
            }
        }

        var result = StringBuilder()
        while(stack.isNotEmpty()){
            result.append(stack.peekFirst())
            stack.removeFirst()
        }

        return result.toString()
    }

    fun backspaceCompare(s: String, t: String): Boolean {
        return getStringHelper(s) == getStringHelper(t)
    }
}