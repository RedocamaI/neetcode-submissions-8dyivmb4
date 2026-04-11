class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> grid(9, 0);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')  continue;

                int grid_no = (i/3)*3 + (j/3);
                int val = board[i][j];

                if(row[i] & (1 << val) ||
                col[j] & (1 << val) ||
                grid[grid_no] & (1 << val)) return false;

                row[i] |= (1 << val);
                col[j] |= (1 << val);
                grid[grid_no] |= (1 << val);
            }
        }

        return true;
    }
};
