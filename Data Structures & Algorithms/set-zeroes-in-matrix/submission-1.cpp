class Solution {
public:
    int n, m;
    void makeZero(int x, int y, vector<vector<int>>& zeros) {
        for(int j=0;j<m;j++)
            zeros[x][j] = 0;
        
        for(int i=0;i<n;i++)
            zeros[i][y] = 0;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        this->n = n;
        this->m = m;

        vector<vector<int>> zeros(n, vector<int>(m, 0));
        zeros = matrix;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] != 0)
                    continue;
                else
                    makeZero(i, j, zeros);
            }
        }

        matrix = zeros;
    }
};
