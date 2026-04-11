class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(auto& num:nums) {
            ump[num]++;
        }

        vector<pair<int, int>> vec;
        for(auto& it:ump) {
            int num = it.first;
            int freq = it.second;

            vec.push_back({freq, num});
        }

        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }

        return ans;
    }
};
