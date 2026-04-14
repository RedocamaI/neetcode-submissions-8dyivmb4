class Solution {
public:
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};

    bool isValid(int i, int j, int n, int m) {
        return !(
            i < 0 || j < 0 || i >= n || j >= m
        );
    }

    int getPerimeter(int i, int j,
    vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if(!isValid(i, j, grid.size(), grid[0].size()) 
        || !grid[i][j])
            return 1;
        if(vis[i][j])
            return 0;
        
        vis[i][j] = 1;
        int perimeter = 0;

        for(int x=0;x<4;x++) {
            int ni = i + di[x];
            int nj = j + dj[x];
            
            perimeter += getPerimeter(ni, nj, vis, grid);
        }

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int xi = -1, xj = -1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j] || !grid[i][j])
                    continue;
                xi = i;
                xj = j;
                break;
            }
            if(xi != -1)
                break;
        }

        int perimeter = getPerimeter(xi, xj, vis, grid);

        return perimeter;
    }
};