class Solution {

    private fun sum(num1: String, num2: String): String{
        val s1 = num1.length; val s2 = num2.length
        var idx1 = s1 - 1; var idx2 = s2 - 1
        val result = StringBuilder()
        var carry = 0
        while(idx1 >= 0 && idx2 >= 0){
            val first = Character.getNumericValue(num1[idx1])
            val second = Character.getNumericValue(num2[idx2])

            val current = first + second + carry

            result.append( current % 10)
            carry = current/10

            idx1 -= 1
            idx2 -= 1
        }

        while(idx1 >= 0){
            val first = Character.getNumericValue(num1[idx1])
            val current = first + carry

            result.append(current % 10)
            carry = current/10

            idx1 -= 1
        }


        while(idx2 >= 0){
            val second = Character.getNumericValue(num2[idx2])
            val current = second + carry

            result.append(current % 10)
            carry = current/10

            idx2 -= 1
        }

        if(carry != 0){
            result.append(carry)
        }

        return result.toString().reversed()
    }

    private fun multiplyHelper(num1: String, num2: Char) : String{
        var idx1 = num1.length - 1
        var carry = 0
        val result = StringBuilder()
        val n = Character.getNumericValue(num2)
        while(idx1 >= 0) {
            val first = Character.getNumericValue(num1[idx1])
            val current = (first * n) + carry
            result.append(current % 10)
            carry = current / 10
            idx1 -= 1
        }

        if(carry != 0){
            result.append(carry)
        }

        return result.toString().reversed()
    }

    fun multiply(num1: String, num2: String): String {

        if(num1 == "0" || num2 == "0"){
            return "0"
        }
        
        val sums = mutableListOf<String>()
        var zeros = 0
        var i = num1.length - 1
        while(i >= 0){
            var current = multiplyHelper(num2, num1[i])
            
            repeat(zeros){
                current = current + "0"
            }
            sums.add(current)
            zeros += 1
            i -= 1
        }

        
        var result = sums.first()
        for(idx in 1 until sums.size){
            result = sum(result, sums[idx])
        }
        return result
    }
}