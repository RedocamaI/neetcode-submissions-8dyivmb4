class Solution {
public:
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};

    bool isValid(int i, int j, int n, int m) {
        return !(
            i < 0 || i >= n || j < 0 || j >= m
        );
    }

    void visitLands(int r, int c, char oc,
    vector<vector<int>>& vis,
    vector<vector<pair<bool, bool>>>& oceans,
    vector<vector<int>>& heights) {
        vis[r][c] = 1;
        if(oc == 'P')
            oceans[r][c].first = true;
        else
            oceans[r][c].second = true;

        int n = heights.size();
        int m = heights[0].size();
        // go to all 4 directions:
        for(int k=0;k<4;k++) {
            int i = r + di[k];
            int j = c + dj[k];

            if(!isValid(i, j, n, m) || vis[i][j])
                continue;
            
            if(heights[i][j] < heights[r][c])
                continue;
            
            visitLands(i, j, oc, vis, oceans, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<pair<bool, bool>>> oceans(n, 
        vector<pair<bool, bool>>(m, {false, false}));

        // for pacific:
        for(int j=0;j<m;j++) {
            if(vis[0][j])
                continue;
            
            visitLands(0, j, 'P', vis, oceans, heights);
        }
        for(int i=0;i<n;i++) {
            if(vis[i][0])
                continue;
            
            visitLands(i, 0, 'P', vis, oceans, heights);
        }

        // for atlantic:
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                vis[i][j] = 0;
        }

        for(int j=0;j<m;j++) {
            if(vis[n-1][j])
                continue;
            
            visitLands(n-1, j, 'A', vis, oceans, heights);
        }
        for(int i=0;i<n;i++) {
            if(vis[i][m-1])
                continue;
            
            visitLands(i, m-1, 'A', vis, oceans, heights);
        }

        // get the final sotred traversals from each oceans
        // check which land can be reached from both: pacific & atlantic
        // push it into the vector
        vector<vector<int>> pacAt;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(oceans[i][j].first && oceans[i][j].second)
                    pacAt.push_back({i, j});
            }
        }

        return pacAt;
    }
};
