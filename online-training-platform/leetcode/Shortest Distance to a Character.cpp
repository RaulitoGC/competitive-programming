class Solution {
public:

    vector<int> shortestToChar(string s, char c) {
        int sz = s.size();
        vector<int> res(sz, INT_MAX);
        int found = -1;
        for(int i = 0 ; i < sz ; i++){
            if(s[i] == c){
                found = i;
            }
            
            if(found != -1){
                res[i] = i - found;
            }
        }
        found = -1;
        for(int i = sz - 1 ; i >= 0 ; i--){
            if(s[i] == c){
                found = i;
            }
            
            if(found != -1){
                res[i] = min(res[i], found - i);
            }
        }
        
        return res;
        
    }
};
