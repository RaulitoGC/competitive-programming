class Solution {
public:
    
    bool isP(string str, int start, int end){
        //cout << str << endl;
        while(start < end){
            if(str[start] != str[end]) return false;
            start++;
            end--;
        }
        
        return true;
    }
    
    void dfs(vector<vector<string>> &res, string &str, int start, vector<string> c){
        int sz = str.size();
        if(start == sz) res.push_back(c);
        for(int end = start; end < sz; end++){
            if(isP(str, start, end)){
                c.push_back(str.substr(start, end - start + 1));
                dfs(res, str, end + 1, c);
                c.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> c;
        dfs(res,s,0,c);
        return res;
    }
};
