class Solution {
public:
    
    vector<string> res;
    
    bool isNotNumber(char c) {
        return c < '0' || c > '9';
    }
    
    char getLowerCase(char c) {
        return (char) tolower(c);
    }
    
    char getUpperCase(char c) {
        return (char) toupper(c);
    }
    
    void backtrack(string& s, string current, int idx) {
        int n = s.size(), size = current.size();
        if(n == size){
            res.push_back(current);
            return;
        }
        
        for(int i = idx ; i < n ; i++) {
            if(isNotNumber(s[i])){
                backtrack(s, current + getLowerCase(s[i]), i + 1);
                backtrack(s, current + getUpperCase(s[i]), i + 1);
            } else {
                backtrack(s, current + s[i], i + 1);
            }
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        string current = "";
        backtrack(s, current, 0);
        return res;
    }
};