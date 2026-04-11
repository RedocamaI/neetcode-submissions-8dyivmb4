class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProd(n, 1);
        vector<int> sufProd(n, 1);

        preProd[0] = nums[0];
        for(int i=1;i<n;i++){
            int val = preProd[i-1]*nums[i];
            preProd[i] = val;
        }

        sufProd[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            int val = sufProd[i+1]*nums[i];
            sufProd[i] = val;
        }

        vector<int> ans(n, 0);
        ans[0] = sufProd[1];
        for(int i=1;i<n-1;i++){
            ans[i] = preProd[i-1] * sufProd[i+1];
        }
        ans[n-1] = preProd[n-2];

        return ans;
    }
};
