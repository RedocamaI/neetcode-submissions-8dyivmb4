class Solution {
public:
    int getDistinctStrings(int i, int l, 
    string str, string s, string t,
    vector<vector<int>>& dp) {
        if(i == s.size())
            return int(l == t.size());
        if(l == t.size())
            return dp[i][l] = 1;
        if(dp[i][l] != -1)
            return dp[i][l];

        // take:
        int take = 0;
        if(s[i] == t[l])
            take = getDistinctStrings(i+1, l+1, str + s[i], s, t, dp);
        // not take:
        int notTake = getDistinctStrings(i+1, l, str, s, t, dp);

        return dp[i][l] = take + notTake;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // return getDistinctStrings(0, 0, "", s, t, dp);

        // base cases:
        for(int i=0;i<n;i++) {
            dp[i][m] = 1;
        }
        dp[n][m] = 1;
        for(int j=1;j<m;j++) {
            dp[n][j] = 0;
        }
        // tabulation:
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                int take = 0;
                if(s[i] == t[j])
                    take = dp[i+1][j+1];
                
                int notTake = dp[i+1][j];

                dp[i][j] = take + notTake;
            }
        }

        return dp[0][0];
    }
};
