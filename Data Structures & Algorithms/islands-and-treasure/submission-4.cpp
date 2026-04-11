class Solution {
public:
    int n, m;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};

    bool isValid(int i, int j) {
        return !(
            i < 0 || i >= n || j < 0 || j >= m
        );
    }

    void bfs(int r, int c,
    vector<vector<int>>& vis,
    vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> bfs;

        bfs.push({{r, c}, 0});
        vis[r][c] = 1;
        while(!bfs.empty()) {
            int i = bfs.front().first.first;
            int j = bfs.front().first.second;
            int d = bfs.front().second;

            bfs.pop();

            int dist = d + 1;
            for(int k=0;k<4;k++) {
                int ni = i + di[k];
                int nj = j + dj[k];

                if(!isValid(ni, nj) || grid[ni][nj] == -1 
                || grid[ni][nj] == 0 || vis[ni][nj])
                    continue;
                if(grid[ni][nj]+1 > 0) {
                    if(dist >= grid[ni][nj])
                        continue;
                }
                
                grid[ni][nj] = dist;
                vis[ni][nj] = 1;
                bfs.push({{ni, nj}, grid[ni][nj]});
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        this->n = n;
        this->m = m;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] != 0)
                    continue;
                
                vector<vector<int>> vis(n, vector<int>(m, 0));
                bfs(i, j, vis, grid);
            }
        }
    }
};
