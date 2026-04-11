class Solution {
public:
    bool doesMatch(int i, int j, int n, int m, string& s, string& p) {
        if(i >= n && j >= m)
            return true;
        if(j >= m)
            return false;

        bool match = (i < n && (s[i] == p[j] || p[j] == '.'));
        if((j+1) < m && p[j+1] == '*') {
            return doesMatch(i, j+2, n, m, s, p) || 
                (match && doesMatch(i+1, j, n, m, s, p));
        }

        if(match)
            return doesMatch(i+1, j+1, n, m, s, p);
        
        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        return doesMatch(0, 0, n, m, s, p);
    }
};
