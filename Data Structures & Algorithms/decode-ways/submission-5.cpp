class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 1 && s[0] != '0')
            return 1;
        if(s[0] == '0')
            return 0;

        int n = s.size();
        vector<int> dp(n+1, -1);

        dp[n-1] = (s[n-1]-'0') != 0;
        string val = to_string(s[n-2]-'0') + to_string(s[n-1]-'0');
        dp[n] = (val[0] != '0' && stoi(val) <= 26);
        for(int i=n-2;i>=0;i--) {
            if(s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            int one = dp[i+1];
            val = to_string(s[i]-'0') + to_string(s[i+1]-'0');
            int two = s[i]-'0' > 2 ? 0 : (
                stoi(val) > 26 ?
                0 : dp[i+2]
            );

            dp[i] = one + two;
        }

        return dp[0];
    }
};
