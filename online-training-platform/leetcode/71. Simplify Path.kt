class Solution {
    fun simplifyPath(path: String): String {
        val items = path.split("/")
        val stack = ArrayDeque<String>()
        
        items.forEach{
            if(it.isNotEmpty()){
                when{
                    it == "." -> {
                        
                    }
                    
                    it == ".." -> {
                        if(stack.size >= 2) {
                            stack.removeFirst()
                            stack.removeFirst()
                        } else if(stack.size >= 1){
                            stack.removeFirst()
                        }
                        
                    }
                    
                    else -> {
                        stack.addFirst("/")
                        stack.addFirst(it)
                    }

                }
            }
        }
        
        val result = StringBuilder()
        while(stack.isNotEmpty()){
            result.append(stack.last())
            stack.removeLast()
        }
        
        return result.toString().takeIf{it.isNotEmpty()} ?: "/"
    }
}