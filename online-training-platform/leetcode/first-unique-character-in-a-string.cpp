class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> M;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            M[s[i]]++;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(M[s[i]] == 1) return i;
        }
        return -1;
    }
};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();