class Solution {

    /**
    Time: O(max(m,n))
    Space: O(m+n)
     */
    fun mergeAlternately(word1: String, word2: String): String {
        val builder = StringBuilder()
        var idx1 = 0; val sz1 = word1.length; 
        var idx2 = 0; val sz2 = word2.length

        while(idx1 < sz1 && idx2 < sz2){
            builder.append(word1[idx1])
            builder.append(word2[idx2])
            idx1 += 1
            idx2 += 1
        }

        while(idx1 < sz1){
            builder.append(word1[idx1])
            idx1 +=1
        }

        while(idx2 < sz2){
            builder.append(word2[idx2])
            idx2 +=1
        }

        return builder.toString()
    }
}