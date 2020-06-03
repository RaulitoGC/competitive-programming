class Solution {
public:
    
    static bool comp(vector<int> v1, vector<int> v2){
        return v1[1] - v1[0] > v2[1] - v2[0];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comp);
        int minCost = 0;
        int size = costs.size();
        for(int i = 0; i < size/2 ; i++){
            minCost += costs[i][0];
        }
        
        for(int i = size/2; i < size ; i++){
            minCost += costs[i][1];
        }
        
        return minCost;
    }
};

auto speedup=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
