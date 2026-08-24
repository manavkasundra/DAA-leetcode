class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int buy_price = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy_price) {
                buy_price = prices[i];
            }
            else if (prices[i] > buy_price + fee) {
                profit += prices[i] - buy_price - fee;
                buy_price = prices[i] - fee;
            }
        }

        return profit;
    }
};