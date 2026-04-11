class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        vector<vector<int>> ans;
        priority_queue<pair<double, int>> mxhp;

        for(int i=0;i<n;i++){

            int x = points[i][0];
            int y = points[i][1];

            double ed = sqrt(pow(x, 2) + pow(y, 2));
            if(mxhp.size() < k){
                mxhp.push({ed, i});
                continue;
            }

            if(ed < mxhp.top().first){
                mxhp.pop();
                mxhp.push({ed, i});
            }
        }

        while(!mxhp.empty()){
            int ind = mxhp.top().second;
            vector<int> point = points[ind];

            ans.push_back(point);
            mxhp.pop();
        }

        return ans;
    }
};
