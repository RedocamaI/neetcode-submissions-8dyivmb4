class Solution {
public:
    vector<int> di = {-1,0,1,0};
    vector<int> dj = {0,-1,0,1};
    vector<vector<char>> board;
    vector<vector<int>> vis;
    int m, n;

    bool isValid(int i, int j) {
        return (i >= 0 && i < n) &&
            (j >= 0 && j < m);
    }

    bool search(string word, int ind, int i, int j) {
        if(ind == word.size())  return true;
        if(!isValid(i, j) || vis[i][j])  return false;
        if(word[ind] != board[i][j])
            return false;

        vis[i][j] = 1;
        for(int x=0;x<4;x++) {
            bool res = search(word, ind+1, i+di[x], j+dj[x]);
            if(res) return true;
        }
        // backtrack:
        vis[i][j] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        this->vis = vis;

        this->board = board;
        this->n = n;
        this->m = m;
        bool ans = false;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(word[0] == board[i][j])
                    ans = search(word, 0, i, j);
                if(ans) return ans;
            }
        }

        return ans;
    }
};
