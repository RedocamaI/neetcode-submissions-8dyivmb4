class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> trips;
        for(auto& trip:triplets) {
            if(target[0] < trip[0] || 
            target[1] < trip[1] ||
            target[2] < trip[2])
                continue;
            
            trips.push_back(trip);
        }

        bool a = false, b = false, c = false;
        for(auto& t:trips) {
            if(t[0] == target[0])
                a = true;
            if(t[1] == target[1])
                b = true;
            if(t[2] == target[2])
                c = true;
        }

        return a && b && c;
    }
};
