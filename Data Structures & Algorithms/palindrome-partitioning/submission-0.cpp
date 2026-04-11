class Solution {
public:
    vector<vector<string>> ans;
    vector<string> sub;

    bool isPal(string s, int l, int r) {
        while(l <= r) {
            if(s[l++] != s[r--])
                return false;
        }

        return true;
    }

    void getSub(int ind, string s) {
        if(ind == s.size()) {
            ans.push_back(sub);
            return;
        }

        for(int i=ind;i<s.size();i++) {
            if(isPal(s, ind, i)) {
                sub.push_back(s.substr(ind, i-ind+1));
                getSub(i+1, s);

                sub.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        getSub(0, s);
        return ans;
    }
};
