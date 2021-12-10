class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if(numRows == 1) {
            return {{1}};
        }
        
        if(numRows == 2) {
            return {{1},{1,1}};
        }
        
        vector<vector<int>> res;
        res.push_back({1});
        res.push_back({1,1});
        for(int i = 2 ; i < numRows ; i++) {
            int n = res.size();
            int lastSize = res[n - 1].size();
            vector<int> current;
            current.push_back(1);
            for(int idx = 1 ; idx < lastSize ; idx++){
                int sum = res[n - 1][idx] + res[n - 1][idx - 1];
                current.push_back(sum);
            }
            current.push_back(1);
            res.push_back(current);
        }
        
        return res;
        
    }
};