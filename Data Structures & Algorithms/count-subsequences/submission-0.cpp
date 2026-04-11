class Solution {
public:
    int getDistinctStrings(int i, int l, 
    string str, string s, string t,
    vector<vector<int>>& dp) {
        if(i == s.size())
            return int(str == t);
        if(l == t.size())
            return dp[i][l] = int(str == t);
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
        vector<vector<int>> dp(n, vector<int>(m+1, -1));

        return getDistinctStrings(0, 0, "", s, t, dp);
    }
};
