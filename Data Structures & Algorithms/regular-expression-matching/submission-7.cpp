class Solution {
public:
    bool isMatching(int i, int j, int n, int m,
    string& s, string& p, vector<vector<int>>& dp) {
        if(i >= n && j >= m)
            return true;
        if(j >= m)
            return false;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool match = i < n && (s[i] == p[j] || p[j] == '.');
        if((j+1) < m && p[j+1] == '*') {
            bool doesMatch = isMatching(i, j+2, n, m, s, p, dp) ||
            (match && isMatching(i+1, j, n, m, s, p, dp));

            return dp[i][j] = doesMatch;
        } 
        
        if(match)
            return dp[i][j] = isMatching(i+1, j+1, n, m, s, p, dp);
        
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return isMatching(0, 0, n, m, s, p, dp);
    }
};
