class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> r;
        int j;
        for(int i = 0; i < prices.size(); i++){
            j = i+1;
            cout << prices[i] << endl;
            
            while( j < prices.size() && prices[j] > prices[i]) j++;
            
            if(j < prices.size()) r.push_back(prices[i] - prices[j]);
            else r.push_back(prices[i]);
        }
        return r;
    }
};
