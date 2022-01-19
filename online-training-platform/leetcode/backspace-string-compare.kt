class Solution {
    
    fun getString(str: String): String{
        val sb = StringBuilder()
        str.forEachIndexed{ idx, c ->
            val sz = sb.length
            if(c == '#' && sz > 0){
                sb.setLength(sz - 1)
            } else if(c != '#'){
                sb.append(c)
            }
        }
        
        return sb.toString()
    }
    
    fun backspaceCompare(s: String, t: String): Boolean {
        
        val ss = getString(s)
        val st = getString(t)
        
        println(ss)
        println(st)
        
        return ss == st
    }
}