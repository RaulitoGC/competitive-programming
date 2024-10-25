class Solution {
    
    fun Char.isVowel() : Boolean {
        
        return this == 'a' || this == 'A' ||
        this == 'e' || this == 'E' ||
        this == 'i' || this == 'I' ||
        this == 'o' || this == 'O' ||
        this == 'u' || this == 'U'
    }
    
    fun reverseVowels(s: String): String {
        val size = s.length
        val indices = mutableListOf<Int>()
        val result = StringBuilder()
        
        s.forEachIndexed { idx, c ->
            result.append(c)
            if(c.isVowel()){
                indices.add(idx)
            }
        }
        
        
        for(i in 0 until indices.size / 2){
            val first = s[indices[i]]
            val last = s[indices[indices.size - i - 1]]
            result.setCharAt(indices[i], last)
            result.setCharAt(indices[indices.size - i - 1], first)
        }
        
        return result.toString()
    }
}