class Solution {
public:
    vector<vector<int>> dp;

    int getEditDistance(int i, int j, int n, int m,
    string word1, string word2) {
        if(i == n) {
            return m-j;
        }
        if(j == m) {
            return (n-i);
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        // same:
        if(word1[i] == word2[j]) {
            return dp[i][j] = getEditDistance(i+1, j+1, n, m, word1, word2);
        }

        // delete:
        int del = 1 + getEditDistance(i+1, j, n, m, word1, word2);

        // replace:
        int replace = 1 + getEditDistance(i+1, j+1, n, m, word1, word2);

        return dp[i][j] = min(replace, del);
    }

    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size())
            return minDistance(word2, word1);
        
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        this->dp = dp;

        return getEditDistance(0, 0, n, m, word1, word2);
    }
};
