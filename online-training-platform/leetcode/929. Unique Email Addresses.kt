class Solution {
    
    private fun getLocalName(email: String): String {
        val currentLocalName = email.split("@").first()
        val idx = currentLocalName.indexOfFirst{it == '+'}
        
        val localName = if(idx == -1 ) currentLocalName else currentLocalName.substring(0, idx)
        
        return localName.replace(".","")
    }   
    
    private fun getDomainName(email: String): String {
        return email.split("@").last()
    }
    // Time : O(n*m) 
    // Space : O(n*m) 
    fun numUniqueEmails(emails: Array<String>): Int {
        
        val set = mutableSetOf<String>()
        emails.forEach{ email ->
            val localName = getLocalName(email)
            val domainName = getDomainName(email)
            val fullEmail = "$localName@$domainName"
            set.add(fullEmail)
        }
        
        return set.size
    }
}