class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxNumber = 10000 + amount;
        vector<int> v(amount + 1, maxNumber);
        v[0] = 0;
        int n = coins.size(), coin;
        for(int i = 0 ; i < n ; i++){
            coin = coins[i];
            for(int j = coin ; j <= amount ; j++){
                v[j] = min(v[j], 1 + v[j - coin]);
            }
        }
        
        return (v[amount] == maxNumber)? -1: v[amount];
    }
};
