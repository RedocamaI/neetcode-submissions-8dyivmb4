class Solution {
public:
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // base:
        vector<int> prev(m, 1);
        
        for(int i=n-2;i>=0;i--) {
            vector<int> cur(m, 0);
            cur[m-1] = 1;

            for(int j=m-2;j>=0;j--) {
                // move down:
                int up = prev[j];
                // move right:
                int down = cur[j+1];
                
                cur[j] = up + down;
            }

            prev = cur;
        }

        return prev[0];
    }
};
