class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++) {
            vector<int> interval = ans.back();
            ans.pop_back();

            if(interval[1] >= intervals[i][0]) {
                interval = {
                    min(interval[0], intervals[i][0]),
                    max(interval[1], intervals[i][1])
                };

                ans.push_back(interval);
                continue;
            }

            ans.push_back(interval);
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};
