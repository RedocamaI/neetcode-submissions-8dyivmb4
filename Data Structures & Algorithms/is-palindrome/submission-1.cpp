class Solution {
public:
    bool checkPal(string s, int i, int j){
        if(i > j)   return true;
        char x = (s[i] >= 'A' && s[i] <= 'Z') ? (char)(s[i]+32) : s[i];
        char y = (s[j] >= 'A' && s[j] <= 'Z') ? (char)(s[j]+32) : s[j];

        if(!((x >= 'a' && x <= 'z') || (x-'0' >= 0 && x-'0' <= 9))){
            return checkPal(s, i+1, j);
        }

        if(!((y >= 'a' && y <= 'z') || (y-'0' >= 0 && y-'0' <= 9))){
            return checkPal(s, i, j-1);
        }

        if(x == y)  return checkPal(s, i+1, j-1);
        return false;
    }

    bool isPalindrome(string s) {
        bool ans = checkPal(s, 0, s.size()-1);

        return ans;
    }
};
