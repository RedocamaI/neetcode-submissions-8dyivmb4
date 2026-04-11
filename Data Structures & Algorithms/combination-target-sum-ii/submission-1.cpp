class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combo;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& can, int t) {
        sort(can.begin(), can.end());
        this->n = can.size();

        getCombos(0, {}, 0, can, t);

        return ans;
    }

    void getCombos(int ind, vector<int> sub, 
    int cur, vector<int>& can, int t) {
        if(cur == t) {
            ans.push_back(sub);
            return;
        }

        for(int i=ind;i<n;i++) {
            if(i > ind && can[i] == can[i-1])
                continue;
            
            if(cur + can[i] > t)    break;

            sub.push_back(can[i]);
            getCombos(i+1, sub, cur+can[i], can, t);

            sub.pop_back();
        }
    }
};
