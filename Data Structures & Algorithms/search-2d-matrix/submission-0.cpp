class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat[0].size();
        int m = mat.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == target) return true;
            }
        }

        return false;
    }
};
