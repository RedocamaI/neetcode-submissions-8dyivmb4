class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        unordered_map<int, int> zeroRows;
        unordered_map<int, int> zeroCols;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == 0) {
                    zeroRows[i]++;
                    zeroCols[j]++;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(zeroRows.find(i) != zeroRows.end()) {
                    matrix[i][j] = 0;
                    continue;
                }

                if(zeroCols.find(j) != zeroCols.end())
                    matrix[i][j] = 0;
            }
        }
    }
};
