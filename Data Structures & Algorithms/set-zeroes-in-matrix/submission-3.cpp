class Solution {
public:
    int n, m;
    void makeZeros(int x, int y, vector<vector<int>>& matrix) {
        for(int i=0;i<n;i++) {
            matrix[i][y] = 0;
        }

        for(int j=0;j<m;j++) {
            matrix[x][j] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        this->n = n;
        this->m = m;
        vector<pair<int, int>> zeros;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == 0)
                    zeros.push_back({i, j});
            }
        }

        if(zeros.size() == n*m)
            return;
        
        for(auto& it:zeros) {
            int i = it.first;
            int j = it.second;
            
            makeZeros(i, j, matrix);
        }
    }
};
