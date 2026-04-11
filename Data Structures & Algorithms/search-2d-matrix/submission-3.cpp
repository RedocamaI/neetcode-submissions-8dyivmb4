class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat[0].size();
        int m = mat.size();

        for(int i=0;i<m;i++){
            int l = 0, h = n-1;
            while(l <= h){
                int mid = l + (h-l)/2;
                if(mat[i][mid] == target)   return true;

                if(mat[i][mid] < target)    l = mid+1;
                else    h = mid-1;
            }

            // if(mat[i][h] == target) return true;
        }

        return false;
    }
};
