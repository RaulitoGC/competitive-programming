class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if(dislikes.empty() ) return true;
        
        unordered_set<int> g1;
        unordered_set<int> g2;
        vector<vector<int>> v,v1;
        
        for(int i = 0 ; i < dislikes.size() ; i++){
            v.push_back(vector<int>{dislikes[i][0], dislikes[i][1]});
        }
        
        while(!v.empty()){
            g1.clear();
            g2.clear();
            g1.insert(v[0][0]);
            g2.insert(v[0][1]);
            v1.clear();
            for(int i = 1 ; i < v.size() ; i++){
                if(g1.count(v[i][0]) == 0 && g2.count(v[i][1]) == 0 && g1.count(v[i][1]) == 0 && g2.count(v[i][0])==0){
                    v1.push_back(vector<int>{v[i][0],v[i][1]});
                    continue;
                }
            
                if(g1.count(v[i][0]) > 0){
                    g1.insert(v[i][0]);
                    g2.insert(v[i][1]);
                }else if(g1.count(v[i][1]) > 0){
                    g1.insert(v[i][1]);
                    g2.insert(v[i][0]);
                }else if(g2.count(v[i][0]) > 0){
                    g1.insert(v[i][1]);
                    g2.insert(v[i][0]);
                }else{
                    g1.insert(v[i][0]);
                    g2.insert(v[i][1]);
                }

                if((g1.count(v[i][0]) > 0 && g2.count(v[i][0]) > 0) || (g1.count(v[i][1]) > 0 && g2.count(v[i][1]) > 0)){
                    return false;
                }
            }
            
            v = v1;
            
        }
        return true;
    }
};
