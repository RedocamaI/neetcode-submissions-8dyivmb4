class Solution {
public:
    int carFleet(int t, vector<int>& pos, vector<int>& sp) {
        int n = pos.size();

        vector<pair<int, int>> ps;
        for(int i=0;i<n;i++){
            ps.push_back({pos[i], sp[i]});
        }

        sort(ps.begin(), ps.end());
        reverse(ps.begin(), ps.end());

        stack<double> times;
        times.push((t-ps[0].first)/(double)ps[0].second);
        for(int i=1;i<n;i++){
            int d = t-ps[i].first;
            int s = ps[i].second;
            double time = d/(double)s;

            if(times.top() < time)  times.push(time);
        }

        return times.size();
    }
};
