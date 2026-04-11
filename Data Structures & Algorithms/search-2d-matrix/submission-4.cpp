class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat[0].size();
        int m = mat.size();

        int l = 0, h = m-1;
        int ind = -1;
        while(l <= h){
            int mid = l + (h-l)/2;

            if(mat[mid][0] == target)   return true;

            if(target > mat[mid][0]){
                if(target <= mat[mid][n-1]){
                    ind = mid;
                    break;
                }

                l = mid+1;
            }
            else     h = mid-1;
        }

        if(ind == -1)   return false;

        l = 0, h = n-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(mat[ind][mid] == target) return true;

            if(mat[ind][mid] < target)  l = mid+1;
            else    h = mid-1;
        }

        return mat[ind][h] == target;
    }
};
