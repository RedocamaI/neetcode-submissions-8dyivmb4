class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuy = prices[0];

        for(auto& price:prices){
            maxProfit = max(maxProfit, price-minBuy);
            minBuy = min(minBuy, price);
        }

        return maxProfit;
    }
};
