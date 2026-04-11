class Solution {
public:
    int n;
    void swapRows(int l, int h, vector<vector<int>>& mat) {
        while(l <= h) {
            for(int j=0;j<n;j++) {
                swap(mat[l][j], mat[h][j]);
            }

            l++;
            h--;
        }
    }

    void transpose(vector<vector<int>>& mat) {
        int x = 0;
        int y = 0;
        while(x < n && y < n) {
            int i = x;
            int j = y;
            while(i < n && j < n) {
                swap(mat[i][y], mat[x][j]);
                i++;
                j++;
            }

            x++;
            y++;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        this->n = n;
        // swap rows:
        swapRows(0, n-1, matrix);

        // transpose of the matrix:
        transpose(matrix);
    }
};
