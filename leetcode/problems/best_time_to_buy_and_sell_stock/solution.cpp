class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprices = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minprices;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
            if (prices[i] < minprices) {
                minprices = prices[i];
            }
        }
        return maxProfit;
    }
};