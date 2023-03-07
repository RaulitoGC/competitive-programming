class Solution {

    private val OPEN = '['
    private val CLOSE = ']'

    private fun getRepeatString(s: String, k: Int): String {
        val sb = StringBuilder()
        repeat(k){
            sb.append(s)
        }

        return sb.toString()
    }

    fun decodeString(s: String): String {
        
        val stack = ArrayDeque<Char>()
        s.forEach{
            if(it != CLOSE) {
                stack.addFirst(it)
            } else {
                val sb = StringBuilder()
                while(stack.isNotEmpty() && stack.peekFirst() != OPEN){
                    sb.append(stack.peekFirst())
                    stack.removeFirst()
                }
                
                stack.removeFirst()
                val sbNumber = StringBuilder()
                while(stack.isNotEmpty() && stack.peekFirst().isDigit()){
                    sbNumber.append(stack.peekFirst())
                    stack.removeFirst()
                }
                println(sbNumber.toString())
                val times = sbNumber.toString().reversed().toInt()
                val repeatString = getRepeatString(sb.toString().reversed(), times)
                repeatString.forEach{
                    stack.addFirst(it)
                }
            }
        }

        val sb = StringBuilder()
        while(stack.isNotEmpty()){
            if(stack.peekFirst().isDigit().not()){
                sb.append(stack.peekFirst())
            }
            stack.removeFirst()
        }

        return sb.toString().reversed()
    }
}