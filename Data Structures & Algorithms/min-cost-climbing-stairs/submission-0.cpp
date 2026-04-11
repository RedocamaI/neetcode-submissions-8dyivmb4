class Solution {
public:
    vector<int> dp;
    int getMinCost(int ind, vector<int>& cost) {
        if(ind >= cost.size())  return 0;
        if(dp[ind] != -1)
            return dp[ind];

        int currCost = cost[ind];
        int st1 = currCost + getMinCost(ind+1, cost);
        int st2 = currCost + getMinCost(ind+2, cost);

        return dp[ind] = min(st1, st2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        this->dp = dp;

        return min(getMinCost(0, cost), getMinCost(1, cost));
    }
};
