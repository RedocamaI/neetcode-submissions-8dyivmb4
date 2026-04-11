class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> ump;
        int n = s.size();
        int l = 0;
        int maxf = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            ump[s[r]]++;
            maxf = max(maxf, ump[s[r]]);

            while(l < r && (r-l+1)-maxf > k){
                ump[s[l]]--;
                l++;
            }
        
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
