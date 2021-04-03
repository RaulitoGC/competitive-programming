class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset ms(A.begin(), A.end());
        vector<int> res;
        for (auto b : B){
            auto it = ms.upper_bound(b);
            res.push_back(ms.extract(it != ms.end() ? it : ms.begin()).value());
        }
        
        return res;
    }
};
