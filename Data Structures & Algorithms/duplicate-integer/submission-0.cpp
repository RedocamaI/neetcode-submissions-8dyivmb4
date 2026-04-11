class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(auto& num:nums) {
            if(ump.find(num) != ump.end())  return true;
            ump[num]++;
        }

        return false;
    }
};