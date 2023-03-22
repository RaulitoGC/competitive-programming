class Solution {
    fun minRemoveToMakeValid(s: String): String {
        val stack = ArrayDeque<Pair<Char, Int>>()

        s.forEachIndexed{ idx, v ->
            if(v == '('){
                stack.addFirst(Pair(v, idx))
            } else if( v == ')') {
                if(stack.isNotEmpty() && stack.peekFirst().first == '('){
                    stack.removeFirst()
                } else {
                    stack.addFirst(Pair(v, idx))
                }
            }
        }

        //println(stack)
        val result = StringBuilder()
        val cache = stack.map{it.second}.toHashSet()

        s.forEachIndexed{ idx, v ->
            if(cache.contains(idx).not()){
                result.append(v)
            }
        }

        return result.toString()
    }
}