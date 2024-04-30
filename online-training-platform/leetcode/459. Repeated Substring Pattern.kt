class Solution {

    fun repeatedSubstringPattern(s: String): Boolean {
        val size = s.length
        val result = MutableList<Int>(size){0}

        if(size == 1){
            return false
        }

        var j = 1; var i = 0;

        while(j < size){
            if(s[j] == s[i]) {
                result[j] = i + 1
                i += 1
                j += 1
            } else {
                if(i != 0 ) {
                    i = result[i - 1]
                } else {
                    result[j] = 0
                    j += 1
                }
            }
        }

        return result[size - 1] != 0 && (result[size - 1] % (size - result[size - 1])) == 0
    }
}