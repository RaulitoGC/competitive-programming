class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> m;
        
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]]++;
        }
        
        int key, res = 0;
        
        if(k > 0){
            for(auto it = m.begin() ; it != m.end() ; it++){
                key = it->first;
                if(m.find(key + k) != m.end()){
                    res++;
                }
            }    
        }else{
            int val;
            for(auto it = m.begin() ; it != m.end() ; it++){
                val = it->second;
                if(val > 1){
                    res++;
                }
            }
        }
        
        return res;
    }
};
