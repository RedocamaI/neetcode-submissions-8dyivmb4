class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto& num:nums) {
            st.insert(num);
        }

        int i = 0;
        int n = nums.size();
        for(auto& val:st) {
            nums[i++] = val;
        }

        return st.size();
    }
};