class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // base case:
        vector<int> prev(m+1, 0);
        prev[m] = 0;
        
        for(int i=n-1;i>=0;i--) {
            vector<int> cur(m+1, -1);
            cur[m] = 0;
            for(int j=m-1;j>=0;j--) {
                if(text1[i] == text2[j]) {
                    cur[j] = 1 + prev[j+1];
                    continue;
                }

                cur[j] = max({
                    prev[j+1],
                    cur[j+1],
                    prev[j]
                });
            }

            prev = cur;
        }

        return prev[0];
    }
};
