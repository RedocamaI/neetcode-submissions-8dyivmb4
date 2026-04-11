class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // brute force:
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int t = -1*a;
            unordered_map<int, int> ump;
            for(int j=i+1;j<n;j++){
                int b = nums[j];
                if(ump.find(t-b) != ump.end()){
                    vector<int> vec = {a, b, t-b};
                    sort(vec.begin(), vec.end());
                    st.insert(vec);
                }
                ump[b]++;
            }
        }

        for(auto& vec:st){
            ans.push_back(vec);
        }

        return ans;
    }
};
