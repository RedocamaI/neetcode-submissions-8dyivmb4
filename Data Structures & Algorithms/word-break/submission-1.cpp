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

    bool checkFurther(int ind, string s, 
    vector<int>& dp, vector<string>& dict) {
        if(ind == s.size())
            return true;
        if(dp[ind] != -1)
            return (dp[ind] == 1);

        bool ans = false;
        for(int i=0;i<dict.size();i++) {
            // need to check for every word in the dict:
            string word = dict[i];

            // matching needs to be done from ind
            // (since that is new start of s)
            if(doesMatch(word, s, ind))
                ans |= checkFurther(ind+word.size(), s, dp, dict);
        }
        dp[ind] = (ans ? 1 : 0);

        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, -1);

        bool ans = false;
        for(int i=0;i<wordDict.size();i++) {
            string word = wordDict[i];
            if(doesMatch(word, s, 0)) {
                ans |= checkFurther(word.size(), s, dp, wordDict);
            }
        }

        return ans;
    }
};
