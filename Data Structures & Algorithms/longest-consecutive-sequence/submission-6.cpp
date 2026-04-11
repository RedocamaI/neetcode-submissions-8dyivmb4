class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;

        // Time: O(n)
        unordered_map<int, int> ump;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
        }

        
        int l = 1;
        int ans = 1;
        int start = -1e9;
        for(int i=0;i<n;i++){
            if(ump.find(nums[i]-1) == ump.end())    start = nums[i];
            else    continue;

            int cur = start+1;
            l = 1;
            while(ump.find(cur) != ump.end()){
                cur++;
                l++;
            }

            ans = max(ans, l);
        }

        return ans;
    }
};
