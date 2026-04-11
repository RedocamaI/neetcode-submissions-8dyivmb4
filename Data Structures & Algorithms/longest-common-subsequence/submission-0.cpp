class Solution {
public:
    int getLcs(int i, int j, int n, int m, 
    string text1, string text2,
    vector<vector<int>>& dp) {
        if(i == n || j == m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];


        // when both chars equal:
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + getLcs(i+1, j+1, n, m, text1, text2, dp);
        
        int tb = getLcs(i+1, j+1, n, m, text1, text2, dp);
        int t2 = getLcs(i, j+1, n, m, text1, text2, dp);
        int t1 = getLcs(i+1, j, n, m, text1, text2, dp);

        return dp[i][j] = max({tb, t2, t1});
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return getLcs(0, 0, n, m, text1, text2, dp);
    }
};
