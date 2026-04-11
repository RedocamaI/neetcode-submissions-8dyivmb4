class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size())
            return minDistance(word2, word1);
        
        int n = word1.size();
        int m = word2.size();
        // n-th row:
        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);
        
        // base case:
        for(int j=0;j<=m;j++)
            prev[j] = m-j;
        // initializing: n-th row & m-th col:
        prev[m] = 0;

        for(int i=n-1;i>=0;i--) {
            cur[m] = n-i;
            for(int j=m-1;j>=0;j--) {
                if(word1[i] == word2[j]) {
                    cur[j] = prev[j+1];
                    continue;
                }

                // delete:
                int del = 1 + prev[j];

                // replace:
                int replace = 1 + prev[j+1];

                cur[j] = min(del, replace);
            }

            prev = cur;
        }

        return prev[0];
    }
};
