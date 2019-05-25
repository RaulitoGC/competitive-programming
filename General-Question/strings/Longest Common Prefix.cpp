class Solution {
public:
    
    string lcp(string s1, string s2){
        int index = 0;
        int minSize = min(s1.size(),s2.size());
        while(index < minSize && s1[index] == s2[index]) index++;
        return s1.substr(0,index);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        
        if( n == 0 ) return "";
        if( n == 1 ) return strs[0];
        if( n == 2) return lcp(strs[0],strs[1]);
        
        sort(strs.begin(),strs.end());
     
        return lcp(strs[0],strs[n-1]);
    }
};