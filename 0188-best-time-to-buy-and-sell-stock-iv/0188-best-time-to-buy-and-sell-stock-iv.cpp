// LeetCode 188 - Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Author: muteeba4266


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // If k is very large, it's like having unlimited transactions
        if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int j = 1; j <= k; j++) {
                // Maximize profit after buying: either keep previous buy or buy at current price
                buy[j] = max(buy[j], sell[j - 1] - price);
                // Maximize profit after selling: either keep previous sell or sell at current price
                sell[j] = max(sell[j], buy[j] + price);
            }
        }

        return sell[k];
    }
};