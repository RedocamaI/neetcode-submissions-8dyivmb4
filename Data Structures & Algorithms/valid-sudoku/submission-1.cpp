class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, int>> rows;
        unordered_map<int, unordered_map<int, int>> cols;
        map<pair<int, int>, unordered_map<int, int>> grid;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')  continue;

                pair<int, int> grid_key = {i/3, j/3};

                if(rows[i].find(board[i][j]) != rows[i].end() ||
                cols[j].find(board[i][j]) != cols[j].end() ||
                grid[grid_key].find(board[i][j]) != grid[grid_key].end())
                    return false;

                rows[i][board[i][j]]++;
                cols[j][board[i][j]]++;
                grid[grid_key][board[i][j]]++;
            }
        }

        return true;
    }
};
