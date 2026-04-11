class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        vector<pair<int, int>> ps;
        int n = pos.size();

        for(int i=0;i<n;i++){
            ps.push_back({pos[i], sp[i]});
        }
        sort(ps.begin(), ps.end());
        
        vector<double> fleets(n, 0);
        for(int i=0;i<n;i++){
            fleets[i] = ((target - ps[i].first)/(double)(ps[i].second));
        }

        int ans = 1;
        for(int i=n-2;i>=0;i--){
            if(fleets[i] > fleets[i+1]) ans++;
            else    fleets[i] = fleets[i+1];
        }

        return ans;
    }
};
