class Solution {
public:
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // base:
        dp[n-1][m-1] = 1;
        for(int j=0;j<m;j++)
            dp[n-1][j] = 1;
        for(int i=0;i<n;i++)
            dp[i][m-1] = 1;
        
        for(int i=n-2;i>=0;i--) {
            for(int j=m-2;j>=0;j--) {
                // move down:
                int up = dp[i+1][j];
                // move right:
                int down = dp[i][j+1];
                
                dp[i][j] = up + down;
            }
        }

        return dp[0][0];
    }
};
