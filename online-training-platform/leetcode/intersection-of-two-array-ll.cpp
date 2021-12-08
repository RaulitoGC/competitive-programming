class Solution {
public:
    
    vector<int> getIntersection(vector<int>& small, vector<int>& big) {
        map<int,int> count;
        for(int num: small){
            count[num]++;
        }
        
        vector<int> res;
        for(int num: big) {
            if(count.find(num) != count.end() && count[num] > 0) {
                res.push_back(num);
                count[num]--;
            }
        }
        
        return res;
    }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        return n < m ? getIntersection(nums1, nums2) : getIntersection(nums2, nums1);
    }
};