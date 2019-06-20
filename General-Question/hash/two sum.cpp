class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> M;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            M.push_back(make_pair(nums[i],i));
        }
        
        sort(M.begin(),M.end());
        
        // for(int i = 0 ; i < n ; i++){
        //     cout << M[i].first << " " << M[i].second << endl;
        // }
        
        auto first = 0;
        auto last = n - 1;
        
        //cout <<" -- ---" << endl;
        
        while(M[first].first + M[last].first != target){
            if(M[first].first + M[last].first > target){
                last--;
            }else{
                first++;
            }
            //cout << M[first].first << " " << M[last].first << endl;
        }
        vector<int> v;
        v.push_back(M[first].second);
        v.push_back(M[last].second);
        sort(v.begin(),v.end());
        return v;
    }
};