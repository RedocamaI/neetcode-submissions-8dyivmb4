class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<char, int> ump;
            int maxFreq = 0;
            for(int j=i;j<n;j++){
                ump[s[j]]++;
                maxFreq = max(maxFreq, ump[s[j]]);
                if((j-i+1) - maxFreq <= k)
                    ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};
