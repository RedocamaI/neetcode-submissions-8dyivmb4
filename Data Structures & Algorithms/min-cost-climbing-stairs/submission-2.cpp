class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int cur = cost[n-1];
        int prev = 0;
        for(int i=n-2;i>=0;i--) {
            int currCost = cost[i];
            int c1 = currCost + cur;
            int c2 = currCost + prev;

            prev = cur;
            cur = min(c1, c2);
        }

        return min(cur, prev);
    }
};
