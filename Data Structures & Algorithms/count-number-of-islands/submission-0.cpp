class Solution {
public:
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};

    bool isValid(int i, int j, int n, int m) {
        return !(
            i < 0 || j < 0 || i >= n || j >= m
        );
    }

    void traverseIsland(int r, int c, 
    vector<vector<char>>& grid, vector<vector<int>>& vis) {
        if(!isValid(r, c, grid.size(), grid[0].size()))
            return;
        if(vis[r][c])
            return;
        if(grid[r][c] == '0')
            return;

        vis[r][c] = 1;
        for(int k=0;k<4;k++) {
            int i = r + di[k];
            int j = c + dj[k];

            traverseIsland(i, j, grid, vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '0' || vis[i][j])
                    continue;
                
                traverseIsland(i, j, grid, vis);
                ans++;
            }
        }

        return ans;
    }
};
