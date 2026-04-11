class Solution {
public:
    set<vector<int>> unq;
    vector<int> sub;
    int n;

    void getCombos(int ind, int t, vector<int>& v) {
        if(t < 0)   return;
        if(ind == n) {
            if(t == 0)
                unq.insert(sub);
            
            return;
        }
        if(t == 0) {
            unq.insert(sub);
            return;
        }


        // take:
        sub.push_back(v[ind]);
        getCombos(ind+1, t-v[ind], v);

        // backtrack:
        sub.pop_back();
        
        // not take:
        getCombos(ind+1, t, v);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& can, int t) {
        sort(can.begin(), can.end());
        this->n = can.size();

        getCombos(0, t, can);

        vector<vector<int>> ans;
        for(auto& v:unq)
            ans.push_back(v);

        return ans;
    }
};
