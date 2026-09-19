class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> maxProfit(100001, 0);

        for (int i = 0; i < difficulty.size(); i++) {
            int diff = difficulty[i];
            maxProfit[diff] = max(maxProfit[diff], profit[i]);
        }

        for (int i = 1; i <= 100000; i++) {
            maxProfit[i] = max(maxProfit[i], maxProfit[i - 1]);
        }

        int totalProfit = 0;
        for (int ability : worker) {
            totalProfit += maxProfit[ability];
        }

        return totalProfit;
    }
};