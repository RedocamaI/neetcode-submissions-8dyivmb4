class Solution {
public:
    int getWays(int ind, string val, string s,
    vector<int>& dp) {
        if(ind == s.size())
            return stoi(val) <= 26;

        if(val.size() > 0 && stoi(val) > 26)  return 0;
        if(dp[ind] != -1)   return dp[ind];

        if(s[ind] == '0')
            return dp[ind] = 0;


        int one = getWays(ind+1, to_string(s[ind]-'0'), s, dp);
        int two = 0;
        if(ind < s.size()-1 && s[ind] <= '2')
            two = getWays(ind+2, 
                to_string(s[ind]-'0') + to_string(s[ind+1]-'0'), s, dp);

        return dp[ind] = one + two;
    }

    int numDecodings(string s) {
        if(s.size() == 1 && s[0] != '0')
            return 1;
        if(s[0] == '0')
            return 0;

        int n = s.size();
        vector<int> dp(n, -1);

        return getWays(0, "", s, dp);
    }
};
