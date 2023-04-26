class Solution {
    fun countAndSay(n: Int): String {
        if(n == 1){
            return "1"
        }

        if(n == 2){
            return "11"
        }

        val previous = countAndSay(n - 1)
        var idx = 0
        val result = StringBuilder()

        while(idx < previous.length) {
            
            val sb = StringBuilder().apply{
                append(previous[idx])
            }

            idx += 1

            while(idx < previous.length && sb.get(0) == previous[idx]){
                sb.append(previous[idx])
                idx += 1
            }
            result.append(sb.length)
            result.append(sb.get(0))

        }
        
        return result.toString()
    }
}