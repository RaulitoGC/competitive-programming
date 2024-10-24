class Solution {
    fun restoreString(s: String, indices: IntArray): String {
        val array = MutableList<Char>(s.length){
            '0'
        }
        
        indices.forEachIndexed{ idx, pos ->
            array[pos] = s[idx]
        }
        
        return array.joinToString("")
    }
}