class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(auto& num:nums) {
            ump[num]++;
        }

        priority_queue<pair<int, int>> max_heap;
        for(auto& it:ump) {
            int num = it.first;
            int freq = it.second;

            max_heap.push({freq, num});
        }

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }

        return ans;
    }
};
