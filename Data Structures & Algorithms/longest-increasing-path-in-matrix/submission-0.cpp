class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return !(
            i < 0 || i >= n || j < 0 || j >= m
        );
    }

    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};

    int getLongestPath(int r, int c,
    vector<vector<int>>& vis,
    vector<vector<int>>& dp,
    vector<vector<int>>& matrix) {
        if(vis[r][c]) {
            if(dp[r][c] != -1)
                return dp[r][c];
            return 0;
        }

        if(dp[r][c] != -1)
            return dp[r][c];
        
        int n = matrix.size();
        int m = matrix[0].size();

        vis[r][c] = 1;
        // explore all 4 directions:
        int maxL = 1;
        for(int k=0;k<4;k++) {
            int i = r + di[k];
            int j = c + dj[k];

            if(!isValid(i, j, n, m))
                continue;
            if(matrix[i][j] <= matrix[r][c])
                continue;
            
            maxL = max(maxL, 1 + getLongestPath(i, j, vis, dp, matrix));
        }

        return dp[r][c] = maxL;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j])   continue;

                getLongestPath(i, j, vis, dp, matrix);
            }
        }

        int ans = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                ans = max(ans, dp[i][j]);
        }

        return ans;
    }
};
