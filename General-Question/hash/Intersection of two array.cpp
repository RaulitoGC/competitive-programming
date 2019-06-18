class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> S;
        unordered_set<int> temp;
        S.insert(nums1.begin(),nums1.end());
        
        for(int n : nums2){
            if(S.count(n) > 0) temp.insert(n);
        }
        vector<int> result;
        for(auto it = temp.begin(); it != temp.end(); it++){
            result.push_back(*it);
        }
        
        return result;
    }
};