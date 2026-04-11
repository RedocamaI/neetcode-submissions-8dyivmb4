class Solution {
public:
    int isOverlapping(vector<int>& a, vector<int>& b) {
        if(a[1] >= b[0] && a[0] <= b[1]) return 0;
        if(a[1] < b[0]) return 1;

        return -1;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;

        ans.push_back(newInterval);
        for(int i=0;i<n;i++) {
            vector<int> interval = ans.back();
            ans.pop_back();

            int status = isOverlapping(intervals[i], interval);
            
            if(status == 0) {
                ans.push_back({
                    min(intervals[i][0], interval[0]),
                    max(intervals[i][1], interval[1])
                });
                continue;
            }if(status < 0) {
                ans.push_back(interval);
                ans.push_back(intervals[i]);
                continue;
            }

            ans.push_back(intervals[i]);
            ans.push_back(interval);
        }

        return ans;
    }
};
