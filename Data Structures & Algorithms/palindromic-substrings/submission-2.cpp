class Solution {
public:
    int noOfPalindromicSubstrings = 0;
    vector<vector<int>> dp;

    bool isPal(int i, int j, string s) {
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }

        return true;
    }

    int countPalindromes(int i, int j, string s) {
        if(i > j)   return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == j) {
            noOfPalindromicSubstrings++;
            return dp[i][j] = 1;
        }

        if(isPal(i, j, s))
            noOfPalindromicSubstrings++;
        
        countPalindromes(i+1, j, s);
        countPalindromes(i, j-1, s);
        countPalindromes(i+1, j-1, s);

        return dp[i][j] = 1;
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        this->dp = dp;

        countPalindromes(0, n-1, s);
        return noOfPalindromicSubstrings;
    }
};
