class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxprofit = 0;
        int minBuy = prices[0];
        for (int i = 1 ;i < prices.size() ; i++){
            if (prices[i] < minBuy){
                minBuy = prices[i];
            }
            profit = prices[i] - minBuy;
            maxprofit = max(maxprofit,profit);
        }
        return maxprofit;
    }
};
