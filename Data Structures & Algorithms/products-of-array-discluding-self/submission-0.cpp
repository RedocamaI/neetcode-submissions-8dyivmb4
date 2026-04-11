class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nz = 0;
        for(auto& num:nums) {
            if(num == 0)    nz++;
        }

        int prod = 1;
        int prodnz1 = 1;
        for(auto& num:nums){
            if(nz == 1 && num == 0){
                prod *= num;
                continue;
            }
            
            prod *= num;
            prodnz1 *= num;
        }

        vector<int> ans;
        for(auto& num:nums) {
            int val = prod;
            if(num)
                val = prod/num;
            else{
                if(nz == 1) val = prodnz1;
            }
            
            ans.push_back(val);
        }

        return ans;
    }
};
