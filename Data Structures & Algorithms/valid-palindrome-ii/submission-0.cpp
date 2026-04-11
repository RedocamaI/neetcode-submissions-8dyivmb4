class Solution {
public:
    bool isPalindrome(int l, int r, string &s) {
        while(l <= r) {
            if(s[l++] != s[r--])
                return false;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;

        while(l <= r) {
            if(s[l] != s[r]) {
                return isPalindrome(l+1, r, s) || isPalindrome(l, r-1, s);
            }

            l++;
            r--;
        }

        return true;
    }
};