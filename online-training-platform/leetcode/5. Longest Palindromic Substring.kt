class Solution {
    fun longestPalindrome(s: String): String {
        
        if(s.length == 1){
            return s[0].toString()
        }

        if(s.length == 2){
            if(s[0] == s[1]){
                return s
            } else {
                return s[0].toString()
            }
        }

        var result = ""

        for(idx in 1 until s.length - 1) {
            var start = idx - 1; var end = idx + 1

            while(start >= 0 && end < s.length){
                if(s[start] == s[end]){
                    start -= 1
                    end += 1
                } else {
                    break
                }
            }

            
            start += 1
            if(end > s.length) end = s.length
            
            val current = s.substring(start, end)
            

            result = if(current.length > result.length) current else result
        }

        for(idx in 0 until s.length - 1) {
            var start = idx; var end = idx + 1

            while(start >= 0 && end < s.length){
                if(s[start] == s[end]){
                    start -= 1
                    end += 1
                } else {
                    break
                }
            }

            
            start += 1
            if(end > s.length) end = s.length
            
            val current = s.substring(start, end)
            

            result = if(current.length > result.length) current else result
        }

        return result
    }
}