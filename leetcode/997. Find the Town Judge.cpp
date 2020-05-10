class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        if(trust.empty()) return (N == 1)? 1: -1;
        
        unordered_map<int,int> um;
        int total = (N*(N+1))/2;
        for(int i = 0 ; i < trust.size() ; i++){
            um[trust[i][1]] += trust[i][0];
            um[trust[i][0]] -= trust[i][1];
        }
        
        int c = 0;
        int judge = 0;
        unordered_map<int,int>::iterator it;
        
        for(it = um.begin() ; it != um.end() ; it++){
            if(it->second == total - it->first){
                judge = it->first;
                c++;
            }
        }
        
        return (c == 1)? judge : -1;
    }
};
