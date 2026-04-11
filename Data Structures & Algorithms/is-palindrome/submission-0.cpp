class Solution {
public:
    bool isPalindrome(string s) {
        string pal = "";
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'a' && s[i] <= 'z' ||
            (s[i]-'0' >= 0 && s[i]-'0' <= 9))  pal += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                pal += (char)(s[i]+32);
            }
        }

        string revPal = pal;
        reverse(revPal.begin(), revPal.end());
        
        return pal == revPal;
    }
};
