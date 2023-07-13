package array_string

import Level
import Question


fun Question.isUnique(str: String) : Boolean{
    return when(level){
        Level.BASIC -> isUniqueBasicImplementation(str)
        Level.INTERMEDIATE -> isUniqueIntermediateImplementation(str)
        Level.ADVANCE -> isUniqueAdvanceLevel(str)
        else -> throw NotImplementedError("This problem does not contain ${level.name} implementation")
    }
}

private fun isUniqueBasicImplementation(str: String): Boolean {
    for(i in str.indices){
        for(j in i + 1 until str.length) {
            if(str[i] == str[j]){
                return false
            }
        }
    }
    return true
}

private fun isUniqueIntermediateImplementation(str: String): Boolean {
    val cache = HashSet<Char>()
    str.forEach {
        if (cache.contains(it)) {
            return false
        }
    }
    return true
}

private fun isUniqueAdvanceLevel(str: String): Boolean {
    if(str.isEmpty()){
        return false
    }

    var result = str.first().toInt()
    for (i in 1 until str.length){
        result = result xor str[i].toInt()
    }
    return result > 0
}

