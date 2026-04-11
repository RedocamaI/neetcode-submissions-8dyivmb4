class Solution {
public:
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};

    bool isValid(int i, int j, int n, int m) {
        return !(
            i < 0 || j < 0 || i >= n || j >= m
        );
    }

    int traverseIsland(int r, int c, int n, int m,
    vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(!isValid(r, c, n, m))
            return 0;
        if(grid[r][c] == 0)
            return 0;
        if(vis[r][c])
            return 0;

        vis[r][c] = 1;
        int area = 1;
        for(int k=0;k<4;k++) {
            int i = r + di[k];
            int j = c + dj[k];

            area += traverseIsland(i, j, n, m, grid, vis);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '0' || vis[i][j])
                    continue;
                
                ans = max(ans, traverseIsland(i, j, n, m, grid, vis));
            }
        }

        return ans;
    }
};
