class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> freq(1001, 0);
        for(auto& num:nums) {
            freq[num]++;
        }

        for(int i=0;i<=1000;i++) {
            if(freq[i] > 1) return i;
        }

        return -1;
    }
};
