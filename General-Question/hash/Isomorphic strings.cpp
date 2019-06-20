class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> M;
        unordered_map<char,char> R;
        int n = s.size();
        for(int i = 0; i < n ; i++){
            if(M.count(s[i]) > 0){
                if(M[s[i]] != t[i]) return false;
            }else{
                if(R.count(t[i]) > 0){
                    if(R[t[i]] != s[i]) return false;
                }
                M[s[i]] = t[i];
                R[t[i]] = s[i];
            }
        }
        return true;
    }
};