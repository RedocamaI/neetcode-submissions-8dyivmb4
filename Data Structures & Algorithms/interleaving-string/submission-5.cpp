class Solution {
public:
    string s3;
    vector<vector<int>> dp;
    bool isInterleavePos(int i, int j, string res, string s1, string s2) {
        if(res.size() == s3.size())
            return dp[i][j] = int(res == s3 && i == s1.size() && j == s2.size());

        if(dp[i][j] != -1)
            return (dp[i][j] == 1);

        // take S1:
        bool takeS1 = false;
        if(i < s1.size() && s1[i] == s3[i+j])
            takeS1 = isInterleavePos(i+1, j, res+s1[i], s1, s2);

        // take S2:
        bool takeS2 = false;
        if(j < s2.size() && s2[j] == s3[i+j]) 
            takeS2 = isInterleavePos(i, j+1, res+s2[j], s1, s2);
        
        return dp[i][j] = int(takeS1 || takeS2);
    }

    bool isInterleave(string s1, string s2, string s3) {
        this->s3 = s3;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        this->dp = dp;

        return isInterleavePos(0, 0, "", s1, s2);
    }
};
