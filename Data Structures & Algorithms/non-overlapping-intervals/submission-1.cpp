class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        int ans = 0;
        vector<vector<int>> nonOverlaps;
        nonOverlaps.push_back(intervals[0]);
        int prevEnd = intervals[0][1];
        for(int i=1;i<n;i++) {
            vector<int> interval = nonOverlaps.back();

            if(interval[1] > intervals[i][0]) {
                prevEnd = min(prevEnd, intervals[i][0]);
                if(interval[1] > intervals[i][1]) {
                    nonOverlaps.pop_back();
                    nonOverlaps.push_back(intervals[i]);
                }
                
                ans++;
                continue;
            }

            nonOverlaps.push_back(intervals[i]);
        }

        return ans;
    }
};
