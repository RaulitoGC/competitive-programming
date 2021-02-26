class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0 ; i< nums.size(); i++){
            m[nums[i]]++;
        }
        map<int, int>::iterator it;
        int i = 0, num;
        vector<int> t;
        for( it = m.begin(); it != m.end() ; it++){
            num = it->second;
            while(num--){
                t.push_back(it->first);
            }
        }
        nums = t;
    }
};
