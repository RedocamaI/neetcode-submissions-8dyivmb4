class Solution {
public:
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};

    bool isValid(int i, int j, int n, int m) {
        return !(
            i < 0 || i >= n || j < 0 || j >= m
        );
    }

    int bfs(vector<vector<int>>& rotten,
    vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minMinutes = -1;

        vector<vector<int>> minTime(n, vector<int>(m, -1));
        queue<pair<pair<int, int>, int>> q;
        for(auto& fruit:rotten) {
            q.push({{fruit[0], fruit[1]}, 0});
        }

        while(!q.empty()) {
            pair<int, int> fruit = q.front().first;
            int time = q.front().second;
            int i = fruit.first;
            int j = fruit.second;
            q.pop();

            for(int k=0;k<4;k++) {
                int ni = i + di[k];
                int nj = j + dj[k];

                if(!isValid(ni, nj, n, m))
                    continue;
                
                if(grid[ni][nj] == 0 || grid[ni][nj] == 2)
                    continue;
                
                if(minTime[ni][nj] == -1 ||
                minTime[ni][nj] > time+1){
                    q.push({{ni, nj}, time+1});
                    minTime[ni][nj] = time+1;
                    minMinutes = max(minMinutes, time+1);
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1 && minTime[i][j] == -1)
                    return -1;
            }
        }

        return minMinutes;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> rotten;
        bool isAnyFresh = false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2)
                    rotten.push_back({i, j});
                if(grid[i][j] == 1)
                    isAnyFresh = true;
            }
        }

        if(!isAnyFresh)
            return 0;
        if(rotten.size() == 0)
            return -1;
        
        return bfs(rotten, grid);
    }
};
