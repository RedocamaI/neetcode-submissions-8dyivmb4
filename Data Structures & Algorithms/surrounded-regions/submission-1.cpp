class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return !(
            i < 0 || i >= n || j < 0 || j >= m
        );
    }

    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};

    bool checkIfSurr(int r, int c,
    vector<vector<int>>& vis, vector<vector<int>>& surr,
    vector<vector<char>>& board) {
        vis[r][c] = 1;
        int n = board.size();
        int m = board[0].size();
        bool isSurr = true;
        for(int k=0;k<4;k++) {
            int i = r + di[k];
            int j = c + dj[k];

            if(!isValid(i, j, n, m)) {
                isSurr = false;
                break;
            }

            if(board[i][j] == 'X')
                continue;
            if(surr[i][j] == 0) {
                isSurr = false;
                break;
            }

            if(vis[i][j])
                continue;
            
            if(!checkIfSurr(i, j, vis, surr, board)) {
                isSurr = false;
                break;
            }
        }

        surr[r][c] = (isSurr ? 1 : 0);
        vis[r][c] = 0;

        return isSurr;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> surr(n, vector<int>(m, -1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == 'X')
                    continue;
                
                checkIfSurr(i, j, vis, surr, board);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(surr[i][j] == 1)
                    board[i][j] = 'X';
            }
        }
    }
};
