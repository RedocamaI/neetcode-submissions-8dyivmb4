class Solution {
public:
    int limit;
    vector<string> ans;

    void getParenthesis(int l, string s, int open, int close) {
        if(l == 0) {
            ans.push_back(s);
            return;
        }

        if(close < open)
            getParenthesis(l-1, s+')', open, close+1);
        if(l > 1 && open < limit)
            getParenthesis(l-1, s+'(', open+1, close);
    }

    vector<string> generateParenthesis(int n) {
        this->limit = n;
        getParenthesis(2*n-1, "(", 1, 0);

        return ans;
    }
};
