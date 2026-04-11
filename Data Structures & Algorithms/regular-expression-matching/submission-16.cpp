class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[n][m] = 1;

        for(int i=n;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                bool match = i < n && (s[i] == p[j] || p[j] == '.');
                if((j+1) < m && p[j+1] == '*') {
                    dp[i][j] = (dp[i][j+2] || 
                        (match && dp[i+1][j]));
                }else
                    dp[i][j] = match && dp[i+1][j+1];
            }
        }

        return dp[0][0];
    }
};
