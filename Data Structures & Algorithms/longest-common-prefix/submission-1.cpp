class Solution {
public:
    string getCommonPrefix(string& str, string& testStr) {
        int n = testStr.size();
        string prefix = "";
        for(int i=0;i<n;i++) {
            if(str[i] != testStr[i])
                break;
            
            prefix += str[i];
        }

        return prefix;
    }

    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        int n = strs.size();
        string prefix = strs[0];
        for(int i=1;i<n;i++) {
            prefix = getCommonPrefix(strs[i], prefix);
            if(prefix.empty())  return prefix;
        }

        return prefix;
    }
};