class Solution {
public:
    int ini = 0;
    int l = 0;

    bool isPal(int i, int j, string s) {
        while(i <= j) {
            if(s[i++] != s[j--])
                return false;
        }

        return true;
    }
    
    void getLongestPalindrome(string s, int i, int j,
    vector<vector<int>>& dp) {
        if(dp[i][j] != -1)
            return;
        if(i == j) {
            if(j-i+1 > l) {
                l = j-i+1;
                ini = i;
            }

            dp[i][j] = 1;
            return;
        }


        if(isPal(i, j, s)) {
            if(j-i+1 > l) {
                l = j-i+1;
                ini = i;
            }

            dp[i][j] = 1;
            return;
        }
        

        dp[i][j] = 0;
        getLongestPalindrome(s, i+1, j, dp);
        getLongestPalindrome(s, i, j-1, dp);
        getLongestPalindrome(s, i+1, j-1, dp);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(1000, vector<int>(1000, -1));

        getLongestPalindrome(s, 0, n-1, dp);

        return s.substr(ini, l);
    }
};
