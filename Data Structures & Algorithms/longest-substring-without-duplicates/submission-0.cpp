class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ump;
        int l = 0, n = s.size();
        int ans = 0;
        for(int r=0;r<n;r++){
            if(l < r && ump.find(s[r]) != ump.end())
                l = max(l, ump[s[r]]+1);
            
            ans = max(ans, r-l+1);
            ump[s[r]] = r;
        }

        return ans;
    }
};
