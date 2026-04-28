class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> ump;
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;

        int ans = 0;
        int n = s.size();

        int i = n-1;
        while(i >= 0) {
            int val = ump[s[i]];
            int num = ump[s[i--]];
            while(i >= 0 && ump[s[i]] < val) {
                num -= ump[s[i]];
                val = ump[s[i]];
                i--;
            }

            ans += num;
        }

        return ans;
    }
};