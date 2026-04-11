class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> store;
        for(int i=0;i<nums.size();i++){
            store.push_back({nums[i], i});
        }

        sort(store.begin(), store.end());

        int i=0, j=store.size()-1;
        while(i <= j){
            int val = store[i].first + store[j].first;

            if(val == target){
                vector<int> vec = {store[i].second, store[j].second};
                sort(vec.begin(), vec.end());
                return vec;
            }
            else if(val > target)    j--;
            else    i++;
        }

        return {-1, -1};
    }
};
