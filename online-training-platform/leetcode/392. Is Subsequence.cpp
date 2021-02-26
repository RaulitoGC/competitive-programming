class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        string str = "";
        
        for(int i = 0, j = 0 ; i < t.size() && j < s.size() ; i++){
            if(s[j] == t[i]){
                j++;    
                str += t[i];
            }
        }
        return str == s;
    }
};
