class Solution {
public:
    
    
    vector<vector<int>> res;
    
    void combineHelper(vector<int> current, int start, int n, int k) {
        
        current.push_back(start);
        
        int size = current.size();
        if(size == k){
            res.push_back(current);
            return;
        }
    
        for(int i = start + 1 ; i <= n ; i++) {
            combineHelper(current, i, n, k);
        }
    } 
    
    vector<vector<int>> combine(int n, int k) {
        for(int i = 1 ; i <= n ; i++) {
            vector<int> current;
            combineHelper(current, i, n, k);    
        }
        return res;
    }
};