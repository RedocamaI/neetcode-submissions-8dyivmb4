class Solution {
public:
    unordered_map<int, vector<char>> ump;
    vector<string> ans;

    void getCombos(int ind, string digits, string val) {
        if(ind == digits.size()) {
            ans.push_back(val);
            return;
        }

        vector<char> v = ump[digits[ind]-'0'];
        for(int i=0;i<v.size();i++) {
            val += v[i];
            getCombos(ind+1, digits, val);
            val.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)  return {};
        
        unordered_map<int, vector<char>> ump;
        ump[2] = {'a','b','c'};
        ump[3] = {'d','e','f'};
        ump[4] = {'g','h','i'};
        ump[5] = {'j','k','l'};
        ump[6] = {'m','n','o'};
        ump[7] = {'p','q','r','s'};
        ump[8] = {'t','u','v'};
        ump[9] = {'w','x','y','z'};
        this->ump = ump;

        getCombos(0, digits, {});
        return ans;
    }
};
