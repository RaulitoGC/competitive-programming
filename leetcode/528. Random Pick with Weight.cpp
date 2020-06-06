class Solution {
public:
    vector<int> p;
    Solution(vector<int>& w) {
        
        int sum = 0;
        p.push_back(w[0]);
        for(int i = 1 ; i < w.size() ; i++){
            p.push_back(w[i] + p[i-1]);
        }
        
    }
    
    int pickIndex() {
        double random = ((double)rand() / (RAND_MAX));
        double target = p[p.size() - 1]*random;
        int left = 0, right = p.size() - 1, mid;
        int pos = 0;
        while(left <= right){
            int mid = (left + (right - left)/2);
            if(target < p[mid]){
                pos = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return pos;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
