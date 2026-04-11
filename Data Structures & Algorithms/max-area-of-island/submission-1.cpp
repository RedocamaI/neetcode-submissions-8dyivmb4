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
        queue<pair<int, int>> bfs;

        int ans  = 1;
        vis[r][c] = 1;
        bfs.push({r, c});
        while(!bfs.empty()) {
            pair<int, int> cell = bfs.front();
            bfs.pop();

            for(int k=0;k<4;k++) {
                int i = cell.first + di[k];
                int j = cell.second + dj[k];

                if(!isValid(i, j, n, m))
                    continue;
                if(grid[i][j] == 0)
                    continue;
                if(vis[i][j])
                    continue;
                
                ans++;
                vis[i][j] = 1;
                bfs.push({i, j});
            }
        }
        
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 0 || vis[i][j])
                    continue;
                
                ans = max(ans, traverseIsland(i, j, n, m, grid, vis));
            }
        }

        return ans;
    }
};
