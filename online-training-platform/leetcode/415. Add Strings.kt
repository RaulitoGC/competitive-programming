class Solution {

    private fun toInt(c: Char) = Character.getNumericValue(c)

    fun addStrings(num1: String, num2: String): String {
        val result = StringBuilder()

        var i = num1.length - 1; var j = num2.length - 1
        var carry = 0
        while(i >= 0 && j >= 0){
            val current = toInt(num1[i]) + toInt(num2[j]) + carry
            result.append(current % 10)
            carry = current / 10
            i -= 1
            j -= 1
        }

        while( i >= 0){
            val current = toInt(num1[i]) + carry
            result.append(current % 10)
            carry = current / 10
            i -= 1
        }

        while( j >= 0){
            val current = toInt(num2[j]) + carry
            result.append(current % 10)
            carry = current / 10
            j -= 1
        }

        if(carry != 0){
            result.append(carry)
        }

        return result.toString().reversed()
    }
}