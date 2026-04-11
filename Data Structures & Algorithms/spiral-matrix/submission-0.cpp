class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;
        int up = 0, down = n-1;
        int left = 0, right = m-1;
        while(up <= down && left <= right) {
            // left to right:
            for(int j=left;j<=right;j++) {
                ans.push_back(matrix[up][j]);
            }
            up++;

            // up to down:
            if(left > right)    break;
            for(int i=up;i<=down;i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(up > down)   break;
            // right to left:
            for(int j=right;j>=left;j--) {
                ans.push_back(matrix[down][j]);
            }
            down--;

            if(left > right)    break;
            // down to up:
            for(int i=down;i>=up;i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }

        return ans;
    }
};
