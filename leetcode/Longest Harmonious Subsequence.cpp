class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;
        int size = nums.size();
        for(int i = 0 ; i < size ; i++){
            m[nums[i]]++;
        }
        
        unordered_map<int,int>::iterator it;
        
        int mx = 0;
        for(it = m.begin() ; it != m.end() ; it++){
            int current = it->first;
            if(m.find(current-1) != m.end()){
                mx = max(mx , m[current-1] + it->second);
            }else if(m.find(current+1) != m.end()){
                mx = max(mx , m[current+1] + it->second);
            }
        }
        
        return mx;
    }
};
