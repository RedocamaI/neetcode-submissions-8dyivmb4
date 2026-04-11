class Solution {
public:
    bool doesMatch(string word, string s, int ind) {
        int n = word.size();
        int m = s.size();

        if(n > m)  return false;

        int i = 0, j = ind;
        while(i < n && j < m) {
            if(word[i++] != s[j++])
                return false;
        }

        return true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);

        dp[n] = true;
        for(int ind=n-1;ind>=0;ind--) {
            for(int i=0;i<wordDict.size();i++) {
                string word = wordDict[i];
                if(ind+word.size() > n)
                    continue;
                
                dp[ind] = dp[ind] || (doesMatch(word, s, ind) && dp[ind+word.size()]);
            }
        }

        return dp[0];
    }
};
