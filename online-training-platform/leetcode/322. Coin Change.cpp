class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
	    dp[0] = 0;
        
        for( int i = 1 ; i <= amount; i++){
            dp[i] = -1;
        }
        
	    sort(coins.begin(), coins.end());

        for(int j = coins[0] ; j <= amount ; j++){
            if(dp[j - coins[0]] != -1){
                dp[j] = dp[j-coins[0]] + 1;
            }
        }
	
        for( int i = 0 ; i < coins.size(); i++){
            // cout << coins[i] << endl;
            for(int j = coins[i] ; j <= amount ; j++){
                if(dp[j - coins[i]] != -1){
                    if(dp[j] != -1){
                        dp[j] = min(dp[j-coins[i]] + 1, dp[j]);
                    }else{
                        dp[j] = dp[j-coins[i]] + 1;
                    }

                }
            }

        }
	
	return dp[amount];
    }
};
