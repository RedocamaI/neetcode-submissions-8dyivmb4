class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        while(!digits.empty()) {
            int dig = carry + digits.back();
            digits.pop_back();

            if(dig == 10) {
                dig = 0;
                carry = 1;
            }else   carry = 0;

            ans.push_back(dig);
        }

        if(carry)
            ans.push_back(carry);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
