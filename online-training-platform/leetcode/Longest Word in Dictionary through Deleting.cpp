class Solution {
public:
    
    bool contains(string s1, string s2){
        int idx = 0;
        for(int i = 0 ; idx < s1.size() && i < s2.size() ; i++){
            if(s1[idx] == s2[i]){
                idx++;
            }
        }
        return idx == s1.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(int i = 0 ; i < d.size() ; i++){
            if(contains(d[i], s)){
                if(d[i].size() > res.size()  || (d[i].size() == res.size() && d[i] < res)){
                    res = d[i];
                }
            }
        }
        return res;
    }
};
