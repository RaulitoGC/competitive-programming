class Solution {
    
public:
    
    static bool order(int x, int y){
        return (x > y);
    }
    
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        
        int t = 0;
        
        while(stones.size() > 1){
            sort(stones.begin(), stones.end(), order);            
            t = stones[0] - stones[1];
            stones.erase(stones.begin());
            stones.erase(stones.begin());
            if(t != 0){
                stones.push_back(t);    
            }
        }
        if(stones.size() == 1) return stones[0];
        else return 0;
    }
};