class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans;
        int n = queries.size();
        int m = intervals.size();
        for(int i=0;i<n;i++) {
            int query = queries[i];
            int l = 1e9;
            for(int j=0;j<m;j++) {
                if(intervals[j][0] <= query && query <= intervals[j][1])
                    l = min(l, intervals[j][1]-intervals[j][0]+1);
            }

            ans.push_back(l == 1e9 ? -1 : l);
        }

        return ans;
    }
};
