class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int money = 0, badge = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            money = max(money, badge + prices[i] - fee);
            badge = max(badge, money - prices[i]);
        }
        return money;
    }
};
