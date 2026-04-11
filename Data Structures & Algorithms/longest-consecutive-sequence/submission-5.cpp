class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        unordered_map<int, int> ump;

        // Time: O(n)
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
        }

        // Time: O(n) - worst case : considering start element is present at last!
        int start = -1e9;
        int l = 1;
        int ans = 1;
        for(int i=0;i<n;i++){
            if(ump.find(nums[i]-1) == ump.end()){
                start = nums[i];
            }else   continue;

            int cur = start+1;
            l = 1;
            while(ump.find(cur) != ump.end()){
                l++;
                cur++;
            }

            ans = max(l, ans);
        }

        return ans;
    }
};
