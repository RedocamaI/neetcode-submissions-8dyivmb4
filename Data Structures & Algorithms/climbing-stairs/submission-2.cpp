class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1)  return 1;

        int prev = 1;
        int pprev = 1;
        for(int i=2;i<=n;i++) {
            int cur = prev + pprev;
            pprev = prev;
            prev = cur;
        }

        return prev;
    }
};
